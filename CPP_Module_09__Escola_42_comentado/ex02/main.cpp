/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:04:05 by maclara-          #+#    #+#             */
/*   Updated: 2023/09/02 18:15:29 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "PmergeMe.hpp"

// 3279, 3064, 3679, 3150, 2406, 3050, 2608, 2332, 48, 4901, 245, 3891, 2523, 2250, 573, 2884, 4465, 2117, 267, 3497, 633, 2816, 4568, 4770, 1056, 3581, 2727, 4707, 205, 4898, 4824, 3484, 2961, 3502, 2397, 1129, 2314, 767, 4225, 3126, 1431, 232, 2016, 3954, 2482, 3352, 1837, 1946, 1231, 2867, 1205, 1865, 1445, 773, 1634, 2502, 116, 124, 2971, 1084, 21, 2794, 4569, 3745, 2058, 2728, 636, 4372, 4258, 4861, 2497, 688, 92, 275, 4642, 3337, 4390, 2241, 1046, 621, 870, 2251, 2486, 3079, 3787, 4883, 580, 4667, 6, 4314, 750, 790, 2107, 1081, 4535, 4928, 3809, 934, 61, 3067

int main(int argc, char **argv) {

    if(argc < 2)
    {
        std::cerr << "Usage: integers in arguments. Example: 0 3 2 5 6 7" << std::endl;
        return 1;
    }

    try
    {
        // -------------------------------- PREPARING --------------------------------

        // put ARGV in vector
        int nb_element = argc - 1; 
        std::vector<int> unsorted;
        for (int i = 1; i < argc; i++)
            unsorted.push_back(atoi(argv[i]));
        
        //check for duplicates 
        for (size_t i = 0; i < unsorted.size(); i++)
        {
            if (std::count(unsorted.begin(), unsorted.end(), unsorted[i]) > 1)
            {
                std::cerr << "Are duplicate " << unsorted[i] << " in sequence" << std::endl;
                return 1;
            }
        }

        //copy vec in deque - to organize in deque
        std::deque<int> deque;
        for (size_t i = 0; i < unsorted.size(); i++)
            deque.push_back(unsorted[i]);
    
        // -------------------------------- VECTOR --------------------------------
        //vector unsorted
        std::cout << std::string(80, '-') << std::endl << std::endl;
        std::cout << "Before: ";
        for (int i = 0; i < argc - 1; i++){
            
            std::cout << unsorted[i] << " ";
            if (i == argc - 2)
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << std::string(80, '-') << std::endl << std::endl;

        //vector unsorted
		std::cout << "VECTOR TESTING" << std::endl;
        PmergeMe pmergeme;
        //vector testing
        clock_t start_time_v = clock();
        Comparator comp = compare;
        std::vector<int> sorted = pmergeme.mergeInsertionSort(comp, unsorted);
        clock_t end_time_v = clock();

        //vector sorted
        std::cout << "After: ";
        for (size_t i = 0; i < sorted.size(); i++){
            
            std::cout << sorted[i] << " ";
            if (i == sorted.size() - 1)
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;

        // Check VECTOR SORTED order
        for (size_t i = 0; i < sorted.size() - 1; i++){
            
            if (sorted[i] > sorted[i + 1]){
                std::cout << "incorret order" << std::endl;
                return 1;
            }
        }
        std::cout << "CHECK VECTOR ORDER - All in correct order!!!" << std::endl << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::vector sort: " << ((double)(end_time_v - start_time_v) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;


        // -------------------------------- DEQUE --------------------------------
        // deque testing
        std::cout << std::string(80, '-') << std::endl;
		std::cout << "DEQUE TESTING" << std::endl << std::endl;
        clock_t start_time_d = clock();
        Comparator comp_d = compare;
        std::deque<int> sorted_d = pmergeme.mergeInsertionSort_deque(comp_d, deque);
        clock_t end_time_d = clock();
        
        std::cout << "After: ";
        for (size_t i = 0; i < sorted_d.size(); i++){
            std::cout << sorted_d[i] << " ";
            if (i == sorted.size() - 1)
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;
        
        // Check order
        for (size_t i = 0; i < sorted_d.size() - 1; i++){
            
            if (sorted_d[i] > sorted_d[i + 1]){
                std::cout << "incorret order" << std::endl;
                return 1;
            }
        }
        std::cout << "CHECK DEQUE ORDER - All in correct order!!!" << std::endl << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::deque sort:   " << ((double)(end_time_d - start_time_d) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        // Analysis of the results vector and deque
        std::cout << std::string(80, '-') << std::endl;

        if (end_time_v - start_time_v > end_time_d - start_time_d)
            std::cout << "RESULT: std::deque is " << (end_time_v - start_time_v) - (end_time_d - start_time_d) << "us faster than std::vector" << std::endl;
        if (end_time_v - start_time_v < end_time_d - start_time_d)
            std::cout << "RESULT: std::vector is  " << (end_time_d - start_time_d) - (end_time_v - start_time_v) << "us faster than std::deque" << std::endl;
        if ((end_time_v - start_time_v) == (end_time_d - start_time_d))
            std::cout << "RESULT: std::vector and std::deque works in same time" << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        std::cout << std::string(80, '-') << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
