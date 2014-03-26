*******************************
Memory Prefetching
*******************************
I implemented sequential prefetching scheme. Whenever an access for block b results in level 2 cache miss, the level 2 caches is checked to see if b+1, b+2, ... b+n are already in cache, where n is the number of prefetch block that are going to be prefetched. If not, then the blocks are fetched from memory. Number of Prefetch block n is varied between 0, 1, 2, 4 as given by the user. Only for unified L2 caches, memory prefetching is enabled by an additional flag in the simple-scalar cache configuration. Memory prefetching fills L2 cache and does not require an additional buffer. 

-------------------------------
Main Changes in cache.c
-------------------------------
The function cache_prefetch_block in cache.c is added to implement memory prefetching. The function is called whenever a L2 cache miss occurs. In the function cache_prefetch_block, it is checked whether the block to be prefetched already exists in the cache or not. If already exists in the cache, no memory access in initiated.
Otherwise, the block is prefetched.  

Commands to run the benchmark anagram:
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:0 anagram.alpha words < anagram.in > anagram_cache_0_out.txt 2> anagram_cache_0_stat.txt
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:1 anagram.alpha words < anagram.in > anagram_cache_1_out.txt 2> anagram_cache_1_stat.txt
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:2 anagram.alpha words < anagram.in > anagram_cache_2_out.txt 2> anagram_cache_2_stat.txt
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:4 anagram.alpha words < anagram.in > anagram_cache_4_out.txt 2> anagram_cache_4_stat.txt

Commands to run the benchmark go:
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:0 go.alpha 2 8 2stone9.in > go_cache_0_out.txt 2> go_cache_0_stat.txt
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:1 go.alpha 2 8 2stone9.in > go_cache_1_out.txt 2> go_cache_1_stat.txt
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:2 go.alpha 2 8 2stone9.in > go_cache_2_out.txt 2> go_cache_2_stat.txt
../sim-outorder -cache:il2 dl2 -cache:dl2 ul2:1024:64:2:l:4 go.alpha 2 8 2stone9.in > go_cache_4_out.txt 2> go_cache_4_stat.txt