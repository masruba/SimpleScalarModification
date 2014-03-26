*******************************
DVFS
*******************************

I enabled support for dynamically changing voltage and frequency scaling factors in sim-wattch. I changed voltage and frequency so that estimated power consumption would be close to the given power budget for the application.

-------------------------------
Main Changes in power.c
-------------------------------
A function dvfs_controller is added in the power.c to implement DVFS mechanism. It is called per DVFS interval. FSF, VSF, 
avg power per cycle are printed in separate files. Those values are needed to plot graphs.

Commands to run the benchmark anagram:
../sim-outorder -dvfs:interval 100000 -dvfs:target_power 100 anagram.alpha words < anagram.in > anagram_dvfs_100_out.txt 2> anagram_dvfs_100_stat.txt
../sim-outorder -dvfs:interval 100000 -dvfs:target_power 70 anagram.alpha words < anagram.in > anagram_dvfs_70_out.txt 2> anagram_dvfs_70_stat.txt
../sim-outorder -dvfs:interval 100000 -dvfs:target_power 25 anagram.alpha words < anagram.in > anagram_dvfs_25_out.txt 2> anagram_dvfs_25_stat.txt

Commands to run the benchmark go:
../sim-outorder -dvfs:interval 100000 -dvfs:target_power 70 go.alpha 2 8 2stone9.in > go_dvfs_70_out.txt 2> go_dvfs_70_stat.txt
../sim-outorder -dvfs:interval 100000 -dvfs:target_power 50 go.alpha 2 8 2stone9.in > go_dvfs_50_out.txt 2> go_dvfs_50_stat.txt
../sim-outorder -dvfs:interval 100000 -dvfs:target_power 25 go.alpha 2 8 2stone9.in > go_dvfs_25_out.txt 2> go_dvfs_25_stat.txt

