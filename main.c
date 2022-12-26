#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_deque_edge edge;
	t_data		data;
	char		*temp;
	int 		i;

	if (argc < 1)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data.arr_data = (char *)ft_calloc(1, sizeof(char));
	i = 1;
	while (argv[i] != NULL)
	{
		temp = data.arr_data;
		if (argument_check(argv[i]) == ERROR)
		{
			return (write(2, "ARGUMENT ERROR\n", 15));
		}
		data.arr_data = ft_strjoin(data.arr_data, ft_strjoin(argv[i], " "));
		free(temp);
		i++;
	}
	if (parse_data(&data, data.arr_data) == -1)
	{
		free_all(&data, &edge); // 다른 부분 오류 났을 때도 프리해주고 오류 출력하게 하기.
		return (write(2, "PARSING ERROR\n", 14));
	}
	if (data.arr == NULL)
		return (write(2, "ALLOCATE ERROR\n", 15));
	if (arranged_check_arr(data) == ERROR)
		return (write(2, "DATA ARRANGED ALREADY\n", 22));
	ft_memset(&edge, 0, sizeof(edge));
    arr_to_deque(data, &edge);
	if (data.num > 5)
	{
		quick_sort_arr(data.arr, data.num); // 정렬 한 다음에 같은 게 있는지 찾아보자.
		if (overlap_check(data) == ERROR)
			return (write(2, "ARGUMENT OVERLAPPED\n", 20));
		A_to_B(&edge, data, data.num);
	}
	else
	{
		little_number_arrange(&edge, data);
	}
	//print_deque(&edge);
	free_all(&data, &edge);
	return (0);
}