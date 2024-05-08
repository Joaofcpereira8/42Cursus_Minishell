int	handle_minus(void)
{
	char	*tmp;

	ft_get_oldpwd();
	if (!ft_strcmp(mini_shell()->oldpwd, mini_shell()->cwd))
	{
		printf("%s\n", mini_shell()->cwd);
		return (0);
	}
	else
	{
		tmp = mini_shell()->cwd;
		mini_shell()->cwd = mini_shell()->oldpwd;
		mini_shell()->oldpwd = ft_strdup(tmp);
		printf("%s\n", mini_shell()->cwd);
		free(tmp);
		return (0);
	}
}

int change_directory(char *path) {
	char *old = mini_shell()->cwd;
	if (chdir(path) == 0) {
		mini_shell()->cwd = getcwd(NULL, 0);
		free(mini_shell()->oldpwd);
		mini_shell()->oldpwd = old;
	}
	return 0;
}


void	mini_cd2(char **args)
{
	if (chdir(args[1]) == 0 || ((args[1][0] == ' ' || (args[1][0] == '~'
			&& !args[1][1]) || (args[1][0] == '-' && args[1][1] == '-'
			&& !args[1][2]) || !args[1]) && chdir("/home/") == 0))
	{
		ft_clean(mini_shell()->oldpwd);
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 0);
	}
}

int	mini_cd(char **args)
{
	if (!args[1] && chdir(getenv("HOME")) == 0)
	{
		if (mini_shell()->oldpwd)
			ft_clean(mini_shell()->oldpwd);
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(0, 0);
	}
	else if (args[1][0] == '-' && !args[1][1])
		return (handle_minus());
	else if (ft_strcmp(args[1], "..") == 0)
		return (change_directory(".."));
	else if (args[1] && args[2])
		return (pars_error('w', 1));
	else if (args[1] && chdir(args[1]) == 0)
		mini_cd2(args);
	else
		return (err_handler('d', args[1], 1));
	return (mini_shell()->exit_status = 0);
}
