/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:44:46 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/14 13:44:49 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
//This function fills the line buffer.
//It will read BUFFER_SIZE characters in each iteration until there's a \n or \0 character in the line buffer.
//Each time through the loop, it will check if there is already data in the left_c buffer, if there is, it will append the new read characters to it.
//If not, it will duplicate the content of the read buffer into the left_c buffer.
//If a \n is found, it will break out of the loop and return the left_c buffer after appending the read characters to it.
}

char	*set_line(char *line_buffer)
{
//This function take the line buffer as parameter, it reads in it until a \n or \0 character is found, meaning the end of a line, or the end of the file.
//This function sets the line_buffer a \0 at the end of the line inside of it and it returns a substring of the buffer from the end of the line, to the end of the buffer.
//This substring is returned as left_c.
}

char	*get_next_line(int fd)
{
//The main function get_next_line mainly makes some check about the file descriptor and the different memory allocation that could go wrong.	
//Once all checks are done, it calls the _fill_line_buffer function to read in the file descriptor until it find a \n or \0 character.
//Once the line variable is filled, we free the buffer so we don't have any memory leaks, since it's not used after that.
//Once the buffer is freed, we set the line with the _set_line function and we return the line, storing the return value of _set_line in a static variable 
//so that next time we call the get_next_line function we have access to the first characters of the line that may have been read before.
//i.e. our file contains 1\n234\0, our BUFFER_SIZE is 4.
//The first time we'll read through the file we'll read 1\n23 so what we are going to store in our static variable is 23 because the next time 
//we call the function on the same file descriptor it will start reading at the 4 character in the file.
}

int	main(void)
{
	printf("%d \n", BUFFER_SIZE);
	return (0);
}
