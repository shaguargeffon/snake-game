#include "config.h"


constexpr unsigned int timer_scale{20};

constexpr unsigned int timer_multiplier_hard{5};
constexpr unsigned int timer_multiplier_normal{10};
constexpr unsigned int timer_multiplier_easy{20};

constexpr unsigned int timer_creation_new_block{timer_multiplier_easy * 10};

constexpr unsigned int game_size_x{2000};
constexpr unsigned int game_size_y{1500};

constexpr unsigned int frame_scope_x{1500};
constexpr unsigned int frame_scope_y{1500};

constexpr unsigned int frame_amount_x{30};
constexpr unsigned int frame_amount_y{30};

constexpr unsigned int element_size_x{40};
constexpr unsigned int element_size_y{40};

constexpr unsigned int start_point_coordinate_x{100};
constexpr unsigned int start_point_coordinate_y{100};

constexpr unsigned int first_snake_x{frame_amount_x/2};
constexpr unsigned int first_snake_y{frame_amount_y/2};

constexpr unsigned int game_snake_max_length{frame_amount_x / 3};
