/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_opencl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:37:52 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 18:08:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define SOURCE_FILENAME		"kernels/fractol.cl"
#define SOURCE_SIZE_MAX		(16 * 1024)

static char	*get_program_source(char const *filename)
{
	int		fd;
	char	*source_str;
	int		source_size;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		error3("failed to open file \"", filename, "\"");
	}
	source_str = malloc(SOURCE_SIZE_MAX + 1);
	source_size = read(fd, source_str, SOURCE_SIZE_MAX + 1);
	close(fd);
	if (source_size < 0)
	{
		error3("failed to read file \"", filename, "\"");
	}
	else if (source_size == SOURCE_SIZE_MAX)
	{
		error3("file \"", filename, "\" is too long");
	}
	source_str[source_size] = '\0';
	return (source_str);
}

static void	create_program(t_prog *program, cl_device_id device_id)
{
	char *const	source_str = get_program_source(SOURCE_FILENAME);
	cl_int		err;

	program->opencl_program = clCreateProgramWithSource(
			program->opencl_context, 1, (char const **)&source_str, NULL, &err);
	if (!(program->opencl_program))
	{
		error1("failed to create an OpenCL program");
	}
	free(source_str);
	err = clBuildProgram(program->opencl_program, 1, &device_id,
			NULL, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		error1("failed to build an OpenCL program");
	}
}

static void	init_buffers(t_win *window)
{
	cl_context const	context = window->program->opencl_context;
	cl_int				err;

	window->opencl_img = clCreateBuffer(context, CL_MEM_WRITE_ONLY,
			window->opencl_global_size * sizeof(int), NULL, &err);
	window->opencl_palette = clCreateBuffer(context, CL_MEM_READ_ONLY,
			sizeof(int) * ITER_MAX, NULL, &err);
	window->opencl_param = clCreateBuffer(context, CL_MEM_READ_ONLY,
			sizeof(t_param), NULL, &err);
	// TODO: check `err` ?
}

static void	init_kernel(t_win *window)
{
	cl_int	err;

	window->opencl_kernel = clCreateKernel(window->program->opencl_program,
			window->type->opencl_kernel_name, &err);
	if (!(window->opencl_kernel) || err != CL_SUCCESS)
	{
		error3("failed to create kernel \"",
				window->type->opencl_kernel_name, "\"");
	}
	err = 0;
	err |= clSetKernelArg(window->opencl_kernel, 0, sizeof(cl_mem),
			&(window->opencl_img));
	err |= clSetKernelArg(window->opencl_kernel, 1, sizeof(cl_mem),
			&(window->opencl_palette));
	err |= clSetKernelArg(window->opencl_kernel, 2, sizeof(cl_mem),
			&(window->opencl_param));
	if (err != CL_SUCCESS)
	{
		error1("failed to set arguments of an OpenCL kernel");
	}
}

void		start_opencl(t_prog *program)
{
	cl_device_id	device_id;
	cl_int			err;
	int				window_index;
	t_win			*window;

	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, NULL);
	program->opencl_context = clCreateContext(0, 1, &device_id,
			NULL, NULL, &err);
	program->opencl_commands = clCreateCommandQueue(program->opencl_context,
			device_id, 0, &err);
	create_program(program, device_id);
	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		window->opencl_global_size = window->options[OPT_INDEX_WIDTH]
				* window->options[OPT_INDEX_HEIGHT];
		init_buffers(window);
		init_kernel(window);
	}
}
