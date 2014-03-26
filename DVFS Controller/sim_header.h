/* cs203A Added by Masruba Tasnim (masruba@gmail.com) for the availabity of sim_cycle in power.c file */
#ifndef SIM_HEADER_H_
#define SIM_HEADER_H_

/* cs203A DVFS Interval - number of cycles (N) that defines DVFS power monitoring interval.*/
int dvfs_interval;

/* cs203A DVFSTargetPower: - target power budget that the DVFS controller will try to achieve at each interval */
double dvfs_target_power;

#endif
