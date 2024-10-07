#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[]) {
	Status(*tests[])(char*, int) = {
		test_dconnoll_init_default_returns_nonNULL, //1
		test_dconnoll_get_size_on_init_default_returns_0, //2
		test_dconnoll_init_c_string_correctly_assigns_size, //3
		test_dconnoll_my_string_compare, //4
		test_dconnoll_my_string_at, //5
		test_dconnoll_my_string_push_back, //6
		test_dconnoll_my_string_get_capacity_on_init_c_string, //7
		test_dconnoll_my_string_concat, //8
		test_dconnoll_my_string_empty_after_init_c_string, //9
		test_dconnoll_my_string_popback_and_my_string_get_size, //10
		test_dconnoll_my_string_push_back_and_my_string_get_capacity, //11
		test_dconnoll_my_string_get_capacity_on_init_default_returns_7, //12
		test_dconnoll_my_string_empty_after_init_default, //13
		test_dconnoll_pop_back_on_empty_my_string_object, //14
		test_dconnoll_resize_feature_within_my_string_pushback, //15
		test_dconnoll_loop_of_pop_back_on_my_string_object, //16
		test_dconnoll_my_string_compare_with_larger_left_string, //17
		test_dconnoll_my_string_compare_with_larger_right_string, //18
		test_dconnoll_popback_and_pushback_on_init_default, //19
		test_dconnoll_my_string_extraction_on_dictionary_dot_txt, //20
		test_dconnoll_my_string_extraction_loop_till_false, //21
		test_dconnoll_init_c_string_returns_nonNULL, //22
		test_dconnoll_my_string_pushback_and_my_string_at, //23
		test_dconnoll_my_c_str, //24
		test_dconnoll_string_at_returns_NULL_if_index_is_greater_than_capacity //25
	};
	int number_of_functions = sizeof(tests) / sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;


	for (i = 0; i < number_of_functions; i++) {
		if (tests[i](buffer, 500) == FAILURE) {
			printf("FAILED: Test %d failed miserably\n", i);
			printf("\t%s\n", buffer);
			failure_count++;
		}
		else {
			//printf("PASS: Test %d passed\n", i);
			//printf("\t%s\n", buffer);
			success_count++;
		}
	}
	printf("Total number of tests: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
	return 0;
}
