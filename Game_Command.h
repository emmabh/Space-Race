#include "Model.h"
#include "Astronaut.h"
#include "Person.h"

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

void do_move_command(Model &model, int, double, double);

void do_work_command(Model &model, int, int);

void do_deposit_command(Model &model, int, int);

void do_stop_command(Model &model, int);

void do_lock_command(Model &model, int, int);

void do_go_command(Model &model);

void do_run_command(Model &model);

void do_quit_command(Model &model);

#endif