OTUS CPP Homework #8
====
---

### Demo:
1. `cmake -B build`;
2. `cmake --build build`;
3. Run one of the folowing commands:
    - `./build/top_words_sync ./files/knigga.txt ./files/gatsby.txt ./files/fight_club.txt ./files/don_quixote.txt` - starts synchronous version;
    - `./build/top_words_async ./files/knigga.txt ./files/gatsby.txt ./files/fight_club.txt ./files/don_quixote.txt` - starts slow asynchronous version;
    - `./build/top_words_async2 ./files/knigga.txt ./files/gatsby.txt ./files/fight_club.txt ./files/don_quixote.txt` - starts more more performant asynchronous version (faster than synchronous version).

### Benchmarks:
Processing of 4 files at the same time was tested:
1. `top_words_sync` - average execution time `200654,2`.

![2023-05-25_17-37.png](bench_proofs%2Fsync%2F2023-05-25_17-37.png)
![2023-05-25_17-37_1.png](bench_proofs%2Fsync%2F2023-05-25_17-37_1.png)
![2023-05-25_17-37_2.png](bench_proofs%2Fsync%2F2023-05-25_17-37_2.png)
![2023-05-25_17-37_3.png](bench_proofs%2Fsync%2F2023-05-25_17-37_3.png)
![2023-05-25_17-37_4.png](bench_proofs%2Fsync%2F2023-05-25_17-37_4.png)

2. `top_words_async` - average execution time `374998,6`.

![2023-05-25_17-40.png](bench_proofs%2Fasync%2F2023-05-25_17-40.png)
![2023-05-25_17-40_1.png](bench_proofs%2Fasync%2F2023-05-25_17-40_1.png)
![2023-05-25_17-40_2.png](bench_proofs%2Fasync%2F2023-05-25_17-40_2.png)
![2023-05-25_17-40_3.png](bench_proofs%2Fasync%2F2023-05-25_17-40_3.png)
![2023-05-25_17-40_4.png](bench_proofs%2Fasync%2F2023-05-25_17-40_4.png)

2. `top_words_async2` - average execution time `154939,4`.

![2023-05-25_17-47.png](bench_proofs%2Fasync2%2F2023-05-25_17-47.png)
![2023-05-25_17-47_1.png](bench_proofs%2Fasync2%2F2023-05-25_17-47_1.png)
![2023-05-25_17-47_2.png](bench_proofs%2Fasync2%2F2023-05-25_17-47_2.png)
![2023-05-25_17-47_3.png](bench_proofs%2Fasync2%2F2023-05-25_17-47_3.png)
![2023-05-25_17-47_4.png](bench_proofs%2Fasync2%2F2023-05-25_17-47_4.png)

### Final notes:

The more files it processes, than more efficient `top_words_async2` is than `top_words_sync`.
But, `top_words_sync` shows best perfomance if files count less than 3 at the same time.

Single file:

![2023-05-25_17-55.png](bench_proofs%2Fsingle_diff%2F2023-05-25_17-55.png)

Two files:

![2023-05-25_17-57.png](bench_proofs%2Fsingle_diff%2F2023-05-25_17-57.png)

Eight files:

![2023-05-25_18-00.png](bench_proofs%2Fsingle_diff%2F2023-05-25_18-00.png)