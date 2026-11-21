/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 04:31:09 by tutku             #+#    #+#             */
/*   Updated: 2026/11/21 05:03:23 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator
easyfind(T &container, int find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);

	if (it == container.end())
	{
		throw NoOccurrenceException();
	}
	return it;
}

/*
find
https://www.geeksforgeeks.org/cpp/std-find-in-cpp/
*/
