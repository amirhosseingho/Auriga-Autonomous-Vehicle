// #ifndef PARALLEL_PARK
// #define PARALLEL_PARK

// #include "Motion.h"
// #if MODE == CITY

// class Parallel_Park : public Motion
// {
// private:
//     bool direction;

//     int sign_distance = 0;
//     int back_distance = 0;
//     int front_distance = 0;
//     int crosstrack_error = 0;
//     int line_direction_parameter = 1;
//     int counter = 0;
//     int block_counter = -1;
//     int right_vl = 0;
    
//     double kappa = 0;
//     double base_angle = 0;
//     double exit_angle = 0;


//     // bool back_obstacle = false;
//     // bool front_obstacle = false;
//     // const int park_space = 430; // TODO: measure
//     // int full_space_counter = 0;
//     // bool current_space = true;
//     // int saved_encoder = 0;
//     // double starting_angle = 0;
//     // int k_counter = 0 ; 
//     // double saved_first_cmps , saved_cmps = 0 ; 
//     // double shift = 0;
    
//     void (Parallel_Park::*current_instruction)();
//     void sign_verification();
//     void start_to_park();
//     void check_block();
//     void park_preparation();
//     void fucking_park_I();
//     void fucking_park_II();
//     void fucking_park_III();
//     void fucking_park_IV();
//     void fucking_park_V();
//     void fucking_exit_I();
//     void fucking_exit_II();
//     void fucking_exit_III();
//     void fucking_exit_IV();
//     void fucking_exit_V();
//     void check_line();
//     void end_parking();
//     int park_speed_controller(bool direction, int speed, int sensitivity);
//     int min_of_back_VLs();
//     int min_of_front_VLs();
    


// //     void check_for_park();
// //     void prepare();
// //     void enter_car_rear();
// //     void enter_car_front();
// //     void correction();
// //     void correction_front();
// //     void correction_back();
// //     void park_done();
// //     void exit_no_front();
// //     void exit_no_back();
// //     void exit_with_obstacles();
// //     void exit_done();
// //     void getting_line_slowly() ;
// //     double refine_angle(int); 
// //     char ESP_data_PP[35] = {0} ; 

// public:
//     void instruction();
//     Parallel_Park();

// };
// #if !defined(NO_GLOBAL_PARALLEL_PARK)
// extern Parallel_Park Parallel;
// #endif
// #endif

// #endif