/*                                                                                                                                                                                                                  
** execute_cmd.c for execution in /home/josse_a/rendu/PSU_2013_minishell                                                                                                                                            
**                                                                                                                                                                                                                  
** Made by a                                                                                                                                                                                                        
** Login   <josse_a@epitech.net>                                                                                                                                                                                    
**                                                                                                                                                                                                                  
** Started on  Mon Dec  9 17:18:57 2013 a                                                                                                                                                                           
** Last update Thu Dec 12 16:38:14 2013 a                                                                                                                                                                           
*/

#include <stdlib.h>
#include "my.h"                                                                                                                                                                                                     
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void    execute_bin(char *binaire, char **envpath, char **env)
{
  char  **binaire_info;
  int   cpt;
  char  *directory_bin;

  cpt = 0;
  binaire_info = my_copy_path(binaire, binaire_info, ' ');
  directory_bin = get_dir_bin(directory_bin, binaire_info[0], envpath);
  /* if (access("/bin/pwd", X_OK) == 0)                                                                                                                                                                             
    my_putstr("test\n");*/
  /* if (binaire_info != NULL)                                                                                                                                                                                      
    {                                                                                                                                                                                                               
      my_putstr(envpath[5]);                                                                                                                                                                                        
      execve("ls", binaire_info, env);                                                                                                                                                                              
    }*/
}

int     execute_cd(char *cd)
{
  char  **params;

  params = my_copy_path(cd, params,  ' ');
  if (chdir(params[1]) == -1 && params == NULL)
    {
      my_putstr("Error, can't change directory\n");
      return (-1);
    }
  free(params);
}

void    execute_commande(char *buffer, char **envpath, char **env)
{
  pid_t pid;
  int   status;

  if (my_strcmp(buffer, "exit") == 0)
    exit(0);
  else if (my_strcmp(buffer, "cd") == 0)
    execute_cd(buffer);
  else
    {
      pid = fork();
      if (pid == -1)
        {
          my_putstr("Error: fork problem\n");
          exit (1);
        }      else if (pid == 0)
        execute_bin(buffer, envpath, env);
      else
        wait(&status);
    }
}
        
