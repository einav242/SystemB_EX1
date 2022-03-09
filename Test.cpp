#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	// 1
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	// 2
	CHECK(nospaces(mat(5, 3, '*', '&')) == nospaces("*****\n"
													"*&&&*\n"
													"*****"));
	// 3
	CHECK(nospaces(mat(1, 1, '@', '%')) == nospaces("@"));

	// 4
	CHECK(nospaces(mat(11, 9, '+', '!')) == nospaces("+++++++++++\n"
	                                                 "+!!!!!!!!!+\n"
													 "+!+++++++!+\n"
													 "+!+!!!!!+!+\n"
													 "+!+!+++!+!+\n"
													 "+!+!!!!!+!+\n"
													 "+!+++++++!+\n"
													 "+!!!!!!!!!+\n"
													 "+++++++++++"));
	// 5
	CHECK(nospaces(mat(3, 3, '&', '.')) == nospaces("&&&\n"
													"&.&\n"
													"&&&"));
	// // 6  
	CHECK(nospaces(mat(1, 5, '$', '@')) == nospaces("$\n"
													"$\n"
													"$\n"
													"$\n"
													"$"));
	// 7
	CHECK(nospaces(mat(7, 1, '-', '&')) == nospaces("-------"));
	// 8
	CHECK(nospaces(mat(5, 7, '*', '*')) == nospaces("*****\n"
													"*****\n"
													"*****\n"
													"*****\n"
													"*****\n"
													"*****\n"
													"*****"));
	// 9
	CHECK(nospaces(mat(5, 5, '^', '&')) == nospaces("^^^^^\n"
													"^&&&^\n"
													"^&^&^\n"
													"^&&&^\n"
													"^^^^^"));
	
	CHECK(nospaces(mat(13, 3, '1', '2')) == nospaces("1111111111111\n"
													 "1222222222221\n"
													 "1111111111111"));
	
	CHECK(nospaces(mat(5, 11, '~', '*')) == nospaces("~~~~~\n"
													 "~***~\n"
													 "~*~*~\n"
													 "~*~*~\n"
													 "~*~*~\n"
													 "~*~*~\n"
													 "~*~*~\n"
													 "~*~*~\n"
													 "~*~*~\n"
													 "~***~\n"
													 "~~~~~"));
	
	CHECK(nospaces(mat(7, 7, '(', '*')) == nospaces("(((((((\n"
													"(*****(\n"
													"(*(((*(\n"
													"(*(*(*(\n"
													"(*(((*(\n"
													"(*****(\n"
													"((((((("));
	
	CHECK(nospaces(mat(15, 1, '/', '-')) == nospaces("///////////////"));
	
	CHECK(nospaces(mat(3,7, '=', '*')) == nospaces("===\n"
												   "=*=\n"
												   "=*=\n"
												   "=*=\n"
											       "=*=\n"
												   "=*=\n"
												   "==="));
	                                             
	// /* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(4, 5, '#', '^'));
	CHECK_THROWS(mat(2, 6, ')', '('));
	CHECK_THROWS(mat(0, 0, '*', '&'));
	CHECK_THROWS(mat(3, 2, '2', '1'));
	CHECK_THROWS(mat(8, -8, '@', '~'));
	CHECK_THROWS(mat(5, 12, '%', '%'));
	CHECK_THROWS(mat(-7, -6, '&', ' '));
	CHECK_THROWS(mat(0, 5, '!', '?'));
	CHECK_THROWS(mat(8, 0, '+', '-'));
	CHECK_THROWS(mat(6, 5, '.', '/'));
    /* Add more test here */
}


/* Add more test cases here */