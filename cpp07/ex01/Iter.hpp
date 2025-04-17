/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:45:57 by asalo             #+#    #+#             */
/*   Updated: 2025/04/17 12:02:52 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP

#include <string>

template <typename T, typename F>
void iter(T* array, size_t len, F function) {
    for (size_t i = 0; i < len; i++)
        function(array[i]);
}

#endif