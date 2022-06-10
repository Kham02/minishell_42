#ifndef MINISHEL_H
# define MINISHEL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

# define FAIL "\x1b[31m"
# define SHCL "\x1b[32m"
# define END "\x1b[0m"

typedef struct s_envp
{
	size_t			order;
	char			*variable;
	char			*val;
	struct s_envp	*next;
}t_envp;

typedef struct s_info
{
	char			*str;
	struct s_envp	*envp;
}t_info;

t_info	info;


int		cd(char *str);
void	free_str(char **str);
int		get_str(char *str);
char	**find_pwd(char **envp);
void	pwd_command(char *str);
void	echo_command(char *str);
char	**built_cmd(char *str, int r, char **envp);
char	**malloc_envp(char **envp);
// char	*b_unset(char *str);

/* ~~~~~~~~~~~~~~*/
char	*get_val_shlvl(char *envp);
char	*get_val_envp(char *envp);
char	*get_var_envp(char *envp);
int		envp_to_lst(char **envp);
size_t	size_list(void);
t_envp	*list_new_envp(char *envp);
void	list_add_back_envp(t_envp *envp, t_envp *new);

int		ft_strcmp(char *s1, char *s2);
void	print(t_envp *envp);
void	b_env(char **envp);
char	**b_unset(char *str, char **envp);
char	**del_var(char *str, char **envp);

#endif