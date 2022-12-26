/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:32:39 by aerrajiy          #+#    #+#             */
/*   Updated: 2022/12/26 23:37:05 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/pipex_bonus.h"

int main(int argc, char *argv[], char *env[])
{
    t_data_file data;

    data.infile  = open(argv[1], O_RDONLY);
    data.outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR,0644);
    data.start   = 3;
    
    wis_execute_first(argv[2], env, data.infile);
    while (data.start < argc - 2)
        execute_c(argv[data.start++], env);
    wis_execute_last(argv[argc - 2], env, data.outfile);
    while (wait(NULL) != -1);
    
    return 0;
}
