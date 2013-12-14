/*                                                                                                                                                                                                                  
** minishell.c for minishell in /home/josse_a/rendu/PSU_2013_minishell                                                                                                                                              
**                                                                                                                                                                                                                  
** Made by a                                                                                                                                                                                                        
** Login   <josse_a@epitech.net>                                                                                                                                                                                    
**                                                                                                                                                                                                                  
** Started on  Wed Dec  4 17:31:43 2013 a                                                                                                                                                                           
** Last update Thu Dec 12 12:50:13 2013 a                                                                                                                                                                           
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

void    minishell(char **env)
{
  char  **envpath;
  char  *commande;
  int   nb;

  envpath = parser(env, envpath);
  while (42)
    {
      my_putstr("$>");
      commande = get_next_line(0);
      execute_commande(commande, envpath, env);
    }
}
