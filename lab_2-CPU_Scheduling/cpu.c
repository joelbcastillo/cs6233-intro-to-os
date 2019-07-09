#include "oslabs.h"
#include <stdbool.h>
#include <stdio.h>

struct PCB NULLPCB = {0, 0, 0, 0, 0, 0, 0};

bool pcb_equal(struct PCB a, struct PCB b)
{
    if (a.process_id != b.process_id)
    {
        return false;
    }
    if (a.arrival_timestamp != b.arrival_timestamp)
    {
        return false;
    }
    if (a.total_bursttime != b.total_bursttime)
    {
        return false;
    }
    if (a.execution_starttime != b.execution_starttime)
    {
        return false;
    }
    if (a.execution_endtime != b.execution_endtime)
    {
        return false;
    }
    if (a.remaining_bursttime != b.remaining_bursttime)
    {
        return false;
    }
    if (a.process_priority != b.process_priority)
    {
        return false;
    }
    return true;
}

struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
    if (pcb_equal(NULLPCB, current_process))
    {
        new_process.execution_starttime = timestamp;
        new_process.total_bursttime = timestamp + new_process.total_bursttime;
        new_process.execution_endtime = new_process.total_bursttime;
        return new_process;
    }
    if (current_process.process_priority < new_process.process_priority) {
        new_process.remaining_bursttime = new_process.total_bursttime;
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        ready_queue[*queue_cnt] = new_process;
        return current_process;
    } else {
        current_process.remaining_bursttime = current_process.total_bursttime - timestamp;
        current_process.execution_endtime = 0;
        ready_queue[*queue_cnt] = current_process;
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = new_process.total_bursttime + timestamp;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
    return NULLPCB;
}

int main(int argc, char const *argv[])
{
    struct PCB ready_queue[QUEUEMAX];
    int queue_cnt = 0;
    struct PCB current_process = {1,1,4,1,5,4,8};
    struct PCB new_process = {2,2,3,0,0,3,6};
    int time_stamp = 2;

    struct PCB result = handle_process_arrival_pp(ready_queue, &queue_cnt, current_process, new_process, time_stamp);

    printf("ready_queue: \n[PID: %i, AT: %i, TBT: %i, EST: %i, EET: %i, RBT: %i, Priority: %i]\n", ready_queue[0].process_id, ready_queue[0].arrival_timestamp, ready_queue[0].total_bursttime, ready_queue[0].execution_starttime, ready_queue[0].execution_endtime, ready_queue[0].remaining_bursttime, ready_queue[0].process_priority);
    printf("queue_cnt: %i\n", queue_cnt);
    printf("PCB: \n[PID: %i, AT: %i, TBT: %i, EST: %i, EET: %i, RBT: %i, Priority: %i]\n", result.process_id, result.arrival_timestamp, result.total_bursttime, result.execution_starttime, result.execution_endtime, result.remaining_bursttime, result.process_priority);
    return 0;
}
