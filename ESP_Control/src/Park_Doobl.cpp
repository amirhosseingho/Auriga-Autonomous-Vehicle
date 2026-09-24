// #include "Parallel_Park.h"
// #if MODE == CITY

// Parallel_Park Parallel;

// Parallel_Park::Parallel_Park() : direction(true), current_instruction(&Parallel_Park::sign_verification) 
// {}

// void Parallel_Park::instruction(){
//     (this->*current_instruction)();
//     vTaskDelay(2); 
// }

// void Parallel_Park::sign_verification(){
//     // uart.debug_println(vision.get_distance_from_sign());
//     vl.start_vl(VB | VBL | VBML | VBMR | VBR | VR);
//     if(vision.get_distance_from_sign() > 200 && vision.get_distance_from_sign() < 300){
//         motion.stop();
//         vTaskDelay(500);
//         sign_distance = (vision.get_distance_from_sign()) + (not_abs(kappa) * 500); //delete    kappa->get.kappa() //edit kapppa gain
//         motor.start_encode();
//         current_instruction = &Parallel_Park::start_to_park;
//     }
//     else{
//         motion.operate(motion.stanley(false), motion.obstacle_controller(15));
//         kappa = motion.mean_kappa();    //delete
//     }
// }

// void Parallel_Park::start_to_park(){
//     if (motor.get_distance_covered_mm() < sign_distance + 180){    //cover sign distance + VL 
//         motion.operate(motion.stanley(false), park_speed_controller(1, 20, 100));
//     }
//     else{
//         crosstrack_error = not_abs(vision.get_distance_from_midline());
//         motion.stop();
//         vTaskDelay(500);
//         motor.start_encode();
//         current_instruction = &Parallel_Park::check_block;
//     }
//     vTaskDelay(2);
// }

// void Parallel_Park::check_block(){ 
//     uart.debug_println("check block");
//     if(motor.get_distance_covered_mm()< 500){
//         motion.operate(motion.stanley(false), park_speed_controller(1, 20 ,50));

//         right_vl = vl.get_data(vl.RIGHT);
//         if(right_vl < (300 + 100 + (1.5 * vision.get_distance_from_midline()))){    //edit : box size + VL to right line + ...
//             counter++;
//         }
//     } 
//     else{
//         if (counter >= 20){
//             motion.stop();
//             vTaskDelay(500);
//             counter = 0;
//             block_counter++;
//             crosstrack_error = not_abs(vision.get_distance_from_midline());
//             motor.start_encode();
//             current_instruction = &Parallel_Park::check_block;
//             if(block_counter == 2){
//                 current_instruction = &Parallel_Park::end_parking;
//             }
//         }
//         else{
//             motor.start_encode();
//             current_instruction = &Parallel_Park::park_preparation;
//         }
//     }
// }

// void Parallel_Park::park_preparation(){
//     if (motor.get_distance_covered_mm() < 370){    // rear wheel + preparation // new : car ass 400 //edit
//         motion.operate(motion.stanley(false), park_speed_controller(1, 30, 50));
//     }
//     else{
//         motion.stop();
//         vTaskDelay(500);
//         base_angle = cmps.get_car_angle();
//         motor.start_encode();
//         current_instruction = &Parallel_Park::fucking_park_I;
//     }
// }

// void Parallel_Park::fucking_park_I(){
//     bool first_move = motion.go_for_angle(35, -100, park_speed_controller(0, 25, 50));
//     if(first_move){
//         current_instruction = &Parallel_Park::fucking_park_II;
//     }
// }

// void Parallel_Park::fucking_park_II(){
//     bool second_move = motion.go_for_distance(150, 0, park_speed_controller(0, 25, 50));//225
//     if(second_move){
//         motion.stop();
//         vTaskDelay(500);
//         current_instruction = &Parallel_Park::fucking_park_III;
//     }
// }

// void Parallel_Park::fucking_park_III(){
//     bool third_move = motion.go_for_distance(320,80,Parallel.park_speed_controller(0, 25, 20));//275-100
//     if(third_move){
//         motion.stop();
//         vTaskDelay(500);
//         current_instruction = &Parallel_Park::fucking_park_IV;

//         // back_distance = Parallel.min_of_back_VLs();
//         // if (back_distance > 200){
//         //     back_distance = 150;
//         // }

//         // if (Parallel.min_of_front_VLs() < 500 || block_counter == 2){     //check the fullness of next block || parking in third block
//         //     current_instruction = &Parallel_Park::fucking_exit_I;
//         // }
//         // else {
//         //     current_instruction = &Parallel_Park::easy_exit;
//         // }
//     }
// }

// void Parallel_Park::fucking_park_IV(){
//     bool fourth_move = motion.go_for_distance(75,-100,Parallel.park_speed_controller(1, 25, 20));
//     if(fourth_move){
//         motion.stop();
//         vTaskDelay(500);
//         current_instruction = &Parallel_Park::fucking_park_V;
//     }
// }

// void Parallel_Park::fucking_park_V(){
//     bool fifth_move = motion.go_for_distance(65, 100, Parallel.park_speed_controller(0, 25, 20));
//     if(fifth_move){
//         motion.stop();
//         vTaskDelay(3000);
//         current_instruction = &Parallel_Park::fucking_exit_I;
//     }
// }

// void Parallel_Park::fucking_exit_I(){
//     bool first_move = motion.go_for_distance(65, 100, Parallel.park_speed_controller(1, 25, 20));
//     if(first_move){
//         motion.stop();
//         vTaskDelay(500);
//         current_instruction = &Parallel_Park::fucking_exit_II;
//     }
// }

// void Parallel_Park::fucking_exit_II(){
//     bool second_move = motion.go_for_distance(75,-100,Parallel.park_speed_controller(0, 25, 20));
//     if(second_move){
//         motion.stop();
//         vTaskDelay(500);
//         current_instruction = &Parallel_Park::fucking_exit_III;
//     }
// }

// void Parallel_Park::fucking_exit_III(){
//     bool third_move = motion.go_for_distance(320,80, Parallel.park_speed_controller(1, 25, 20));
//     if(third_move){
//         motion.stop();
//         vTaskDelay(500);
//         current_instruction = &Parallel_Park::fucking_exit_IV;
//     }
// }

// void Parallel_Park::fucking_exit_IV(){
//     bool fourth_move = motion.go_for_distance(50, 0, park_speed_controller(1, 25, 50));
//     if(fourth_move){
//         current_instruction = &Parallel_Park::fucking_exit_V;
//     }
// }

// void Parallel_Park::fucking_exit_V(){
//     bool fifth_move = motion.go_for_angle(40, -100, park_speed_controller(1, 25, 50));
//     if(fifth_move){
//         motion.stop();
//         vTaskDelay(500);
//         motor.start_encode();
//         line_direction_parameter = vision.get_line_direction();
//         current_instruction = &Parallel_Park::check_line;
//     }
// }

// void Parallel_Park::check_line(){
//     if(line_direction_parameter == 0){
//         if(motion.go_for_angle(10, -90, motion.obstacle_controller(25))){
//             motion.stop();
//             vTaskDelay(1000);
//             line_direction_parameter = vision.get_line_direction();
//         }
//     }
//     else if(line_direction_parameter == 3){
//         if(motion.go_for_distance(100, 0, motion.obstacle_controller(25))){
//             line_direction_parameter = vision.get_line_direction();
//         }
//     }
//     else{
//         current_instruction = &Parallel_Park::end_parking;
//     }
// }

// void Parallel_Park::end_parking(){
//     vision.set_sign(vision.TRAVERSE);
//     motion.reset_kappa_parameter(); //delete
//     for(int i = 0; i < 15; i++){
//         kappa_arr[i] = 0;
//     }
//     vision.set_distance_from_sign(0);
//     current_instruction = &Parallel_Park::sign_verification;
// }

// int Parallel_Park::min_of_back_VLs(){
//     int back_distance = min(vl.get_data(vl.BACK_MID_LEFT),vl.get_data(vl.BACK));
//     back_distance = min(back_distance, vl.get_data(vl.BACK_MID_RIGHT));

//     return back_distance;
// }

// int Parallel_Park::min_of_front_VLs(){
//     int front_distance = min(vl.get_data(vl.FRONT_MID_LEFT),vl.get_data(vl.FRONT));
//     front_distance = min(front_distance, vl.get_data(vl.FRONT_MID_RIGHT));
//     front_distance = min(front_distance , 4 * vl.get_data(vl.FRONT_RIGHT));

//     return front_distance;
// }

// int Parallel_Park::park_speed_controller(bool direction, int park_speed, int sensitivity){   //1:front   0:back
//     int speed = 0;
//     if(direction){
//         int obstacle_distance = Parallel.min_of_front_VLs();
//         if(obstacle_distance < sensitivity){
//             speed = 0;
//         }
//         else{
//             speed = park_speed;
//         }
//     }
//     else{
//         int obstacle_distance = Parallel.min_of_back_VLs();
//         if(obstacle_distance < sensitivity){
//             speed = 0;
//         }
//         else{
//             speed = -park_speed;
//         }
//     }

//     return speed;
// }

// #endif