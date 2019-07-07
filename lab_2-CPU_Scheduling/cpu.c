#include "oslabs.h"
#include <stdbool.h>

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
    return NULLPCB;
}

int main(int argc, char const *argv[])
{
    return 0;
}
