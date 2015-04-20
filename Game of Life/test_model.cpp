////
////  test_model.cpp
////  Game of Life
////
////  Created by Sergey Bogolepov on 11/2/14.
////  Copyright (c) 2014 Sergey Bogolepov. All rights reserved.
////
//
//#include "test_model.h"
//#include <iostream>
//
//TEST_F(FieldModelTest, TestOfTest) {
//    std::vector<std::pair<int, int>> points = {
//        {1, 1},
//        {2, 2},
//        {1, 3},
//        {1, 2}
//    };
//    std::vector<std::pair<int, int>> point = { {1, 1} };
//    field_model.set_field_size(4);
//    EXPECT_TRUE(field_model.get_field_size() == 4);
//    field_model.set_field(points);
//    field_model.set_needed_to_born({3});
//    field_model.set_needed_to_live({2, 3});
//    field_model.update();
//    auto field = field_model.get_field();
//    ASSERT_TRUE(field[3][2] == false);
//    ASSERT_TRUE(field[2][2] == true);
//}
//
//TEST_F(FieldModelTest, OneCellTest) {
//    std::vector<std::pair<int, int>> points = {
//        {0,0}
//    };
//    field_model.set_field_size(1);
//    field_model.set_field(points);
//    field_model.set_needed_to_born({3});
//    field_model.set_needed_to_live({2, 3});
//    field_model.update();
//    auto field = field_model.get_field();
//    ASSERT_TRUE(field[0][0] == false);
//}
//
//TEST_F(FieldModelTest, PowerfulCellTest) {
//    std::vector<std::pair<int, int>> points = {
//        {0,0}
//    };
//    field_model.set_field_size(4);
//    field_model.set_field(points);
//    field_model.set_needed_to_born({1});
//    field_model.set_needed_to_live({0});
//    field_model.update();
//    auto field = field_model.get_field();
//    ASSERT_TRUE(field[0][0] == true);
//    ASSERT_TRUE(field[0][1] == true);
//    ASSERT_TRUE(field[0][3] == true);
//    ASSERT_TRUE(field[1][0] == true);
//    ASSERT_TRUE(field[1][1] == true);
//    ASSERT_TRUE(field[1][3] == true);
//    ASSERT_TRUE(field[3][0] == true);
//    ASSERT_TRUE(field[3][1] == true);
//    ASSERT_TRUE(field[3][3] == true);
//}
//
////High load!
//TEST_F(FieldModelTest, FromNowhereTest) {
//    field_model.set_field_size(10000);
//    field_model.set_field({});
//    field_model.set_needed_to_born({0});
//    field_model.set_needed_to_live({1,2,3,4,5,6,7,8});
//    field_model.update();
//    auto field = field_model.get_field();
//    
//    for (int i = 0; i < 10000; i++) {
//        for (int j = 0; j < 10000; j++) {
//            ASSERT_TRUE(field[i][j]);
//        }
//    }
//}
//
//TEST_F(FieldModelTest, CornersTest) {
//    std::vector<std::pair<int, int>> points = {
//        {0,0},
//        {3,3},
//        {3,0},
//        {0,3}
//    };
//    field_model.set_field_size(4);
//    field_model.set_field(points);
//    field_model.set_needed_to_born({0});
//    field_model.set_needed_to_live({3});
//    field_model.update();
//    auto field = field_model.get_field();
//    ASSERT_TRUE(field[0][0]);
//    ASSERT_TRUE(field[3][0]);
//    ASSERT_TRUE(field[0][3]);
//    ASSERT_TRUE(field[3][3]);
//    ASSERT_TRUE(!field[1][1]);
//}
//
//
