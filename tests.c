#include <check.h>
#include "logic.h"


START_TEST(test_final_links_setup) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    ck_assert_int_eq(st[0].count_links, 2);
    ck_assert_int_eq(st[1].count_links, 3);
    ck_assert_int_eq(st[2].count_links, 2);
    ck_assert_int_eq(st[3].count_links, 2);
    ck_assert_int_eq(st[4].count_links, 2);
    ck_assert_int_eq(st[5].count_links, 4);
    ck_assert_int_eq(st[6].count_links, 2);
    ck_assert_int_eq(st[7].count_links, 2);
    ck_assert_int_eq(st[8].count_links, 4);
    ck_assert_int_eq(st[9].count_links, 1);

    free_stations(st);
}
END_TEST



START_TEST(test_set_station_links) {
    STATION st100 = {.name="st100", .count_links = 0, .steps=unknown};
    STATION st200 = {.name="st200", .count_links = 0, .steps=unknown};
    STATION st300 = {.name="st300", .count_links = 0, .steps=unknown};
    STATION st400 = {.name="st400", .count_links = 0, .steps=unknown};

    set_station_links(&st100, 3, &st200, &st300, &st400);

    ck_assert_int_eq(st100.count_links, 3);
}
END_TEST

START_TEST(test_steps_setter_from_st1) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[0], 0);

    ck_assert_int_eq(st[0].steps, 0);
    ck_assert_int_eq(st[1].steps, 1);
    ck_assert_int_eq(st[2].steps, 1);
    ck_assert_int_eq(st[3].steps, 2);
    ck_assert_int_eq(st[4].steps, 2);
    ck_assert_int_eq(st[5].steps, 2);
    ck_assert_int_eq(st[6].steps, 3);
    ck_assert_int_eq(st[7].steps, 3);
    ck_assert_int_eq(st[8].steps, 3);
    ck_assert_int_eq(st[9].steps, 4);

    free_stations(st);
}
END_TEST






START_TEST(test_steps_setter_from_st2) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[1], 0);

    ck_assert_int_eq(st[0].steps, 1);
    ck_assert_int_eq(st[1].steps, 0);
    ck_assert_int_eq(st[2].steps, 2);
    ck_assert_int_eq(st[3].steps, 1);
    ck_assert_int_eq(st[4].steps, 1);
    ck_assert_int_eq(st[5].steps, 2);
    ck_assert_int_eq(st[6].steps, 3);
    ck_assert_int_eq(st[7].steps, 2);
    ck_assert_int_eq(st[8].steps, 3);
    ck_assert_int_eq(st[9].steps, 4);

    free_stations(st);
}
END_TEST


START_TEST(test_steps_setter_from_st3) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[2], 0);

    ck_assert_int_eq(st[0].steps, 1);
    ck_assert_int_eq(st[1].steps, 2);
    ck_assert_int_eq(st[2].steps, 0);
    ck_assert_int_eq(st[3].steps, 2);
    ck_assert_int_eq(st[4].steps, 3);
    ck_assert_int_eq(st[5].steps, 1);
    ck_assert_int_eq(st[6].steps, 2);
    ck_assert_int_eq(st[7].steps, 3);
    ck_assert_int_eq(st[8].steps, 2);
    ck_assert_int_eq(st[9].steps, 3);

    free_stations(st);
}
END_TEST



START_TEST(test_steps_setter_from_st4) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[3], 0);

    ck_assert_int_eq(st[0].steps, 2);
    ck_assert_int_eq(st[1].steps, 1);
    ck_assert_int_eq(st[2].steps, 2);
    ck_assert_int_eq(st[3].steps, 0);
    ck_assert_int_eq(st[4].steps, 2);
    ck_assert_int_eq(st[5].steps, 1);
    ck_assert_int_eq(st[6].steps, 2);
    ck_assert_int_eq(st[7].steps, 3);
    ck_assert_int_eq(st[8].steps, 2);
    ck_assert_int_eq(st[9].steps, 3);

    free_stations(st);
}
END_TEST


START_TEST(test_steps_setter_from_st5) {

    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[4], 0);

    ck_assert_int_eq(st[0].steps, 2);
    ck_assert_int_eq(st[1].steps, 1);
    ck_assert_int_eq(st[2].steps, 3);
    ck_assert_int_eq(st[3].steps, 2);
    ck_assert_int_eq(st[4].steps, 0);
    ck_assert_int_eq(st[5].steps, 3);
    ck_assert_int_eq(st[6].steps, 3);
    ck_assert_int_eq(st[7].steps, 1);
    ck_assert_int_eq(st[8].steps, 2);
    ck_assert_int_eq(st[9].steps, 3);

    free_stations(st);
}
END_TEST



START_TEST(test_steps_setter_from_st6) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[5], 0);

    ck_assert_int_eq(st[0].steps, 2);
    ck_assert_int_eq(st[1].steps, 2);
    ck_assert_int_eq(st[2].steps, 1);
    ck_assert_int_eq(st[3].steps, 1);
    ck_assert_int_eq(st[4].steps, 3);
    ck_assert_int_eq(st[5].steps, 0);
    ck_assert_int_eq(st[6].steps, 1);
    ck_assert_int_eq(st[7].steps, 2);
    ck_assert_int_eq(st[8].steps, 1);
    ck_assert_int_eq(st[9].steps, 2);

    free_stations(st);
}
END_TEST



START_TEST(test_steps_setter_from_st7) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[6], 0);

    ck_assert_int_eq(st[0].steps, 3);
    ck_assert_int_eq(st[1].steps, 3);
    ck_assert_int_eq(st[2].steps, 2);
    ck_assert_int_eq(st[3].steps, 2);
    ck_assert_int_eq(st[4].steps, 3);
    ck_assert_int_eq(st[5].steps, 1);
    ck_assert_int_eq(st[6].steps, 0);
    ck_assert_int_eq(st[7].steps, 2);
    ck_assert_int_eq(st[8].steps, 1);
    ck_assert_int_eq(st[9].steps, 2);

    free_stations(st);
}
END_TEST


START_TEST(test_steps_setter_from_st8) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[7], 0);

    ck_assert_int_eq(st[0].steps, 3);
    ck_assert_int_eq(st[1].steps, 2);
    ck_assert_int_eq(st[2].steps, 3);
    ck_assert_int_eq(st[3].steps, 3);
    ck_assert_int_eq(st[4].steps, 1);
    ck_assert_int_eq(st[5].steps, 2);
    ck_assert_int_eq(st[6].steps, 2);
    ck_assert_int_eq(st[7].steps, 0);
    ck_assert_int_eq(st[8].steps, 1);
    ck_assert_int_eq(st[9].steps, 2);

    free_stations(st);
}
END_TEST



START_TEST(test_steps_setter_from_st9) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[8], 0);

    ck_assert_int_eq(st[0].steps, 3);
    ck_assert_int_eq(st[1].steps, 3);
    ck_assert_int_eq(st[2].steps, 2);
    ck_assert_int_eq(st[3].steps, 2);
    ck_assert_int_eq(st[4].steps, 2);
    ck_assert_int_eq(st[5].steps, 1);
    ck_assert_int_eq(st[6].steps, 1);
    ck_assert_int_eq(st[7].steps, 1);
    ck_assert_int_eq(st[8].steps, 0);
    ck_assert_int_eq(st[9].steps, 1);

    free_stations(st);
}
END_TEST


START_TEST(test_steps_setter_from_st10) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[9], 0);

    ck_assert_int_eq(st[0].steps, 4);
    ck_assert_int_eq(st[1].steps, 4);
    ck_assert_int_eq(st[2].steps, 3);
    ck_assert_int_eq(st[3].steps, 3);
    ck_assert_int_eq(st[4].steps, 3);
    ck_assert_int_eq(st[5].steps, 2);
    ck_assert_int_eq(st[6].steps, 2);
    ck_assert_int_eq(st[7].steps, 2);
    ck_assert_int_eq(st[8].steps, 1);
    ck_assert_int_eq(st[9].steps, 0);

    free_stations(st);
}
END_TEST



START_TEST(test_finding_smallest_prev_1) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[0], 0);

    STATION *st6 = &st[5];
    STATION * prev = smallest_prev(st6);

    ck_assert_str_eq(prev->name, "St #3");

    free_stations(st);
}
END_TEST


START_TEST(test_finding_smallest_prev_2) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[9], 0);

    STATION *st3 = &st[2];
    STATION * prev = smallest_prev(st3);

    ck_assert_str_eq(prev->name, "St #6");

    free_stations(st);
}
END_TEST


START_TEST(test_finding_smallest_prev_3) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    set_steps(&st[4], 0);

    STATION *st7 = &st[6];
    STATION * prev = smallest_prev(st7);

    ck_assert_str_eq(prev->name, "St #9");

    free_stations(st);
}
END_TEST



START_TEST(test_finding_smallest_prev_4) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    // может быть и "St #4" и "St #5"  
    // зависит от того как линковали в "setup_all_stations_link"

    set_steps(&st[8], 0); 

    STATION *st2 = &st[1];
    STATION * prev = smallest_prev(st2);

    ck_assert_str_eq(prev->name, "St #4");

    free_stations(st);
}
END_TEST



START_TEST(test_finding_path_from_1_to_10) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    STATION * start = &st[0];
    STATION * end = &st[9];

    STATION * path[max_path_station];
    int count_st = 0;

    find_path(start, end, path, &count_st);

    ck_assert_str_eq(path[0]->name, "St #1");
    ck_assert_str_eq(path[1]->name, "St #3");
    ck_assert_str_eq(path[2]->name, "St #6");
    ck_assert_str_eq(path[3]->name, "St #9");
    ck_assert_str_eq(path[4]->name, "St #10");

    free_stations(st);
}
END_TEST



START_TEST(test_finding_path_from_1_to_7) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    STATION * start = &st[0];
    STATION * end = &st[6];

    STATION * path[max_path_station];
    int count_st = 0;

    find_path(start, end, path, &count_st);

    ck_assert_str_eq(path[0]->name, "St #1");
    ck_assert_str_eq(path[1]->name, "St #3");
    ck_assert_str_eq(path[2]->name, "St #6");
    ck_assert_str_eq(path[3]->name, "St #7");

    free_stations(st);
}
END_TEST


START_TEST(test_finding_path_from_4_to_3) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    STATION * start = &st[3];
    STATION * end = &st[2];

    STATION * path[max_path_station];
    int count_st = 0;

    find_path(start, end, path, &count_st);

    ck_assert_str_eq(path[0]->name, "St #4");
    ck_assert_str_eq(path[1]->name, "St #6");
    ck_assert_str_eq(path[2]->name, "St #3");

    free_stations(st);
}
END_TEST



START_TEST(test_finding_path_from_7_to_5) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    STATION * start = &st[6];
    STATION * end = &st[4];

    STATION * path[max_path_station];
    int count_st = 0;

    find_path(start, end, path, &count_st);

    ck_assert_str_eq(path[0]->name, "St #7");
    ck_assert_str_eq(path[1]->name, "St #9");
    ck_assert_str_eq(path[2]->name, "St #8");
    ck_assert_str_eq(path[3]->name, "St #5");

    free_stations(st);
}
END_TEST



START_TEST(test_finding_path_from_6_to_1) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    STATION * start = &st[5];
    STATION * end = &st[0];

    STATION * path[max_path_station];
    int count_st = 0;

    find_path(start, end, path, &count_st);

    ck_assert_str_eq(path[0]->name, "St #6");
    ck_assert_str_eq(path[1]->name, "St #3");
    ck_assert_str_eq(path[2]->name, "St #1");

    free_stations(st);
}
END_TEST


START_TEST(test_finding_path_from_10_to_1) {
    STATION* st = init_stations();
    setup_all_stations_links(st);

    STATION * start = &st[9];
    STATION * end = &st[0];

    STATION * path[max_path_station];
    int count_st = 0;

    find_path(start, end, path, &count_st);

    ck_assert_str_eq(path[0]->name, "St #10");
    ck_assert_str_eq(path[1]->name, "St #9");
    ck_assert_str_eq(path[2]->name, "St #6");
    ck_assert_str_eq(path[3]->name, "St #3");
    ck_assert_str_eq(path[4]->name, "St #1");

    free_stations(st);
}
END_TEST




int main(void) {
    Suite *s;
    SRunner *sr;

    s = suite_create("main"); // Create the test suite
    TCase *essentials = tcase_create("core");
    suite_add_tcase(s, essentials);

    tcase_add_test(essentials, test_final_links_setup);
    tcase_add_test(essentials, test_set_station_links);

    tcase_add_test(essentials, test_steps_setter_from_st1);
    tcase_add_test(essentials, test_steps_setter_from_st2);
    tcase_add_test(essentials, test_steps_setter_from_st3);
    tcase_add_test(essentials, test_steps_setter_from_st4);
    tcase_add_test(essentials, test_steps_setter_from_st5);
    tcase_add_test(essentials, test_steps_setter_from_st6);
    tcase_add_test(essentials, test_steps_setter_from_st7);
    tcase_add_test(essentials, test_steps_setter_from_st8);
    tcase_add_test(essentials, test_steps_setter_from_st9);
    tcase_add_test(essentials, test_steps_setter_from_st10);

    tcase_add_test(essentials, test_finding_smallest_prev_1);
    tcase_add_test(essentials, test_finding_smallest_prev_2);
    tcase_add_test(essentials, test_finding_smallest_prev_3);
    tcase_add_test(essentials, test_finding_smallest_prev_4);

    tcase_add_test(essentials, test_finding_path_from_1_to_10);
    tcase_add_test(essentials, test_finding_path_from_1_to_7);
    tcase_add_test(essentials, test_finding_path_from_4_to_3);
    tcase_add_test(essentials, test_finding_path_from_7_to_5);
    tcase_add_test(essentials, test_finding_path_from_6_to_1);
    tcase_add_test(essentials, test_finding_path_from_10_to_1);


    tcase_set_timeout(essentials, 0);

    sr = srunner_create(s); // Create a test runner
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed) ? 1 : 0;
}