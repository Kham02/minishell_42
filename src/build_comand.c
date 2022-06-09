#include "../includes/minishell.h"

// int	change_directory(char **str)
// {
// 	// int	len;
// 	char	*s;

// 	// len = ft_strlen(str);
// 	s = str[1];
// 	printf ("print_s: %s\n", s);
// 	if (ft_strncmp(str[0], "cd", 2) == 0)
// 	{
// 		if (chdir(s) != 0)
// 			printf("%s\n", "no such file or directory");
// 	}
// 	return (0);
// }

// ** Определяем билд команду ** //

void	built_cmd(char *str, int r)
{
	if (r == 1)
		cd(str);
	if (r == 2)
		pwd_command(str);
	if (r == 3)
		echo_command(str);
	if (r == 4)
		b_unset(str);
	// if (r == 5)
	// if (r == 6)
}

// ** Выполнение функции CD ** //

int cd(char *str)
{
	char **new_str;

	new_str = ft_split(str, ' ');
	if (new_str[1])
	{
		if (chdir(new_str[1]) != 0)
		{
			printf("cd: no such file or directory: %s\n", new_str[1]);
			free_str(new_str);
			return (1);
		}
	}
	else
		chdir("..");
	free_str(new_str);
	return (0);
}

// ** Выполнение функции PWD ** //

void	pwd_command(char *str)
{
	char *print_pwd;
	char **check;

	check = ft_split(str, ' ');
	print_pwd = malloc(sizeof(char) * 200);
	getcwd(print_pwd, 190);
	if (check[1] && (ft_strncmp(check[1], "-", 1) == 0))
	{
		if ((ft_strncmp(check[1], "-L\0", 3) == 0) || (ft_strncmp(check[1], "-P\0", 3) == 0) ||
				(ft_strncmp(check[1], "-LP\0", 4) == 0))
			printf("%s\n", print_pwd);
		else
			printf("pwd: usage: pwd [-LP]\n");
	}
	else
		printf("%s\n", print_pwd);
	free(print_pwd);
	free_str(check);
}

// ** Выполнение функции ECHO ** //

void	echo_command(char *str)
{
	char **check;

	check = ft_split(str, ' ');
	if (check[1])
	{
		if (ft_strncmp(check[1], "-n\0", 2) == 0)
		{
			if (check[2])
				printf("%s", check[2]);
		}
	}
	else
		printf("\n");
	free_str(check);
}

// int	echo_cmd(char **envp, char *str)
// {
// 	int	i;
// 	int	n;
// 	int	len;
// 	int	len2;
// 	char	*str2;

// 	i = 0;
// 	n = 0;
// 	len2 = 0;
// 	len = ft_strlen(str);
// 	str2 = ft_substr(str, 1, len - 1);
// 	while (ft_strnstr(envp[i], str2, 4) == 0)
// 		i++;
// 	if (!ft_strncmp(envp[i], str2, len - 1))
// 	{
// 		while (envp[i][n] != '=')
// 			n++;
// 		n++;
// 		free(str2);
// 		len2 = ft_strlen(envp[i]) - len;
// 		str2 = ft_substr(envp[i], len, len2);
// 		printf("%s\n", str2);
// 	}
// 	return (0);
// }