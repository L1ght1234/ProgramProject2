results for /02: 

```
=== count_if Performance Analysis ===
Variant 4: count_if
Predicate: counting even numbers
Hardware threads: 12
================================================================================


--- Data size: 1000000 elements ---

1. Sequential count_if (no policy):
   Time: 1.19 ms
   Result: 499899

2. count_if with execution policies:
   execution::seq: 1.19 ms
   execution::par: 0.34 ms
   execution::par_unseq: 0.23 ms
   Speedup par vs seq: 3.46x
   Speedup par_unseq vs seq: 5.13x

3. Custom parallel count_if (different thread counts K):
          K      Time (ms)        Speedup      Result
   --------------------------------------------------
          1           1.41           0.84      499899
          2           0.78           1.53      499899
          3           0.62           1.94      499899
          4           0.50           2.38      499899
          5           0.45           2.68      499899
          6           0.42           2.82      499899
          7           0.45           2.66      499899
          8           0.44           2.73      499899
          9           0.44           2.72      499899
         10           0.44           2.69      499899
         11           0.46           2.62      499899
         12           0.49           2.46      499899
         13           0.48           2.48      499899
         14           0.50           2.37      499899
         15           0.53           2.26      499899
         16           0.56           2.14      499899
         17           0.58           2.06      499899
         18           0.61           1.97      499899
         19           0.64           1.86      499899
         20           0.66           1.81      499899
         21           0.68           1.75      499899
         22           0.70           1.72      499899
         23           0.73           1.63      499899
         24           0.76           1.57      499899
         25           0.78           1.52      499899
         26           0.80           1.49      499899
         27           0.83           1.44      499899
         28           0.83           1.44      499899
         29           0.86           1.39      499899
         30           0.88           1.36      499899
         31           0.93           1.28      499899
         32           0.95           1.25      499899
         33           0.98           1.22      499899
         34           1.00           1.20      499899
         35           1.02           1.17      499899
         36           1.04           1.15      499899

   Best K: 6
   Hardware threads: 12
   K/threads ratio: 0.50
   Best time: 0.42 ms
   Maximum speedup: 2.82x

--- Data size: 10000000 elements ---

1. Sequential count_if (no policy):
   Time: 11.92 ms
   Result: 4999013

2. count_if with execution policies:
   execution::seq: 11.97 ms
   execution::par: 1.84 ms
   execution::par_unseq: 1.82 ms
   Speedup par vs seq: 6.50x
   Speedup par_unseq vs seq: 6.59x

3. Custom parallel count_if (different thread counts K):
          K      Time (ms)        Speedup      Result
   --------------------------------------------------
          1          12.32           0.97     4999013
          2           6.32           1.89     4999013
          3           4.34           2.75     4999013
          4           3.59           3.32     4999013
          5           2.66           4.48     4999013
          6           2.30           5.19     4999013
          7           2.72           4.38     4999013
          8           2.54           4.70     4999013
          9           2.30           5.18     4999013
         10           2.29           5.22     4999013
         11           2.11           5.65     4999013
         12           2.05           5.82     4999013
         13           2.65           4.50     4999013
         14           2.50           4.76     4999013
         15           2.57           4.64     4999013
         16           2.54           4.70     4999013
         17           2.57           4.63     4999013
         18           2.48           4.80     4999013
         19           2.40           4.97     4999013
         20           2.39           5.00     4999013
         21           2.33           5.11     4999013
         22           2.27           5.24     4999013
         23           2.18           5.46     4999013
         24           2.50           4.77     4999013
         25           2.49           4.79     4999013
         26           2.35           5.08     4999013
         27           2.35           5.07     4999013
         28           2.39           4.98     4999013
         29           2.34           5.09     4999013
         30           2.43           4.91     4999013
         31           2.34           5.08     4999013
         32           2.33           5.13     4999013
         33           2.37           5.03     4999013
         34           2.29           5.20     4999013
         35           2.34           5.09     4999013
         36           2.34           5.10     4999013

   Best K: 12
   Hardware threads: 12
   K/threads ratio: 1.00
   Best time: 2.05 ms
   Maximum speedup: 5.82x

--- Data size: 50000000 elements ---

1. Sequential count_if (no policy):
   Time: 59.64 ms
   Result: 25001953

2. count_if with execution policies:
   execution::seq: 59.81 ms
   execution::par: 9.01 ms
   execution::par_unseq: 8.97 ms
   Speedup par vs seq: 6.64x
   Speedup par_unseq vs seq: 6.66x

3. Custom parallel count_if (different thread counts K):
          K      Time (ms)        Speedup      Result
   --------------------------------------------------
          1          60.35           0.99    25001953
          2          30.20           1.97    25001953
          3          20.22           2.95    25001953
          4          15.26           3.91    25001953
          5          12.57           4.75    25001953
          6          11.62           5.13    25001953
          7          15.04           3.97    25001953
          8          13.02           4.58    25001953
          9          11.64           5.12    25001953
         10          10.55           5.65    25001953
         11           9.79           6.09    25001953
         12           9.12           6.54    25001953
         13          11.71           5.09    25001953
         14          11.25           5.30    25001953
         15          11.73           5.08    25001953
         16          11.39           5.23    25001953
         17          10.96           5.44    25001953
         18          10.73           5.56    25001953
         19          10.51           5.67    25001953
         20          10.45           5.71    25001953
         21          10.25           5.82    25001953
         22          10.28           5.80    25001953
         23          10.28           5.80    25001953
         24          10.36           5.76    25001953
         25          10.11           5.90    25001953
         26          10.01           5.96    25001953
         27          10.34           5.77    25001953
         28          10.36           5.75    25001953
         29          10.46           5.70    25001953
         30          10.23           5.83    25001953
         31          10.12           5.89    25001953
         32          10.04           5.94    25001953
         33          10.12           5.89    25001953
         34          10.03           5.95    25001953
         35           9.99           5.97    25001953
         36           9.97           5.98    25001953

   Best K: 12
   Hardware threads: 12
   K/threads ratio: 1.00
   Best time: 9.12 ms
   Maximum speedup: 6.54x


=== CONCLUSIONS ===
1. Execution policies (par, par_unseq) show significant speedup
   on large datasets compared to sequential execution.

2. Custom parallel algorithm performs best when K is close to
   the number of hardware threads available.

3. When K exceeds optimal value, execution time increases due to
   thread creation and synchronization overhead.

4. Compilation with /O2 provides significant performance improvement
   compared to /Od (no optimization).

NOTE: For optimization level comparison, compile the program with
      /Od (no optimization) and /O2 (maximum optimization) flags.
```
results for /0d: 
```
=== count_if Performance Analysis ===
Variant 4: count_if
Predicate: counting even numbers
Hardware threads: 12
================================================================================


--- Data size: 1000000 elements ---

1. Sequential count_if (no policy):
   Time: 9.94 ms
   Result: 500725

2. count_if with execution policies:
   execution::seq: 11.03 ms
   execution::par: 1.48 ms
   execution::par_unseq: 1.39 ms
   Speedup par vs seq: 7.45x
   Speedup par_unseq vs seq: 7.92x

3. Custom parallel count_if (different thread counts K):
          K      Time (ms)        Speedup      Result
   --------------------------------------------------
          1          10.17           0.98      500725
          2           5.38           1.85      500725
          3           3.65           2.73      500725
          4           2.74           3.62      500725
          5           2.24           4.43      500725
          6           1.95           5.09      500725
          7           2.09           4.76      500725
          8           1.94           5.13      500725
          9           1.74           5.72      500725
         10           1.63           6.08      500725
         11           1.56           6.38      500725
         12           1.61           6.18      500725
         13           2.00           4.96      500725
         14           1.96           5.07      500725
         15           1.86           5.33      500725
         16           1.91           5.20      500725
         17           1.74           5.71      500725
         18           1.76           5.66      500725
         19           1.69           5.90      500725
         20           1.69           5.88      500725
         21           1.65           6.04      500725
         22           1.64           6.05      500725
         23           1.63           6.08      500725
         24           1.66           6.00      500725
         25           1.70           5.85      500725
         26           1.73           5.76      500725
         27           1.71           5.80      500725
         28           1.74           5.72      500725
         29           1.74           5.71      500725
         30           1.74           5.71      500725
         31           1.72           5.79      500725
         32           1.75           5.69      500725
         33           1.72           5.80      500725
         34           1.74           5.71      500725
         35           1.72           5.78      500725
         36           1.76           5.63      500725

   Best K: 11
   Hardware threads: 12
   K/threads ratio: 0.92
   Best time: 1.56 ms
   Maximum speedup: 6.38x

--- Data size: 10000000 elements ---

1. Sequential count_if (no policy):
   Time: 98.43 ms
   Result: 4997207

2. count_if with execution policies:
   execution::seq: 110.26 ms
   execution::par: 13.07 ms
   execution::par_unseq: 13.10 ms
   Speedup par vs seq: 8.44x
   Speedup par_unseq vs seq: 8.42x

3. Custom parallel count_if (different thread counts K):
          K      Time (ms)        Speedup      Result
   --------------------------------------------------
          1          98.39           1.00     4997207
          2          49.60           1.98     4997207
          3          33.24           2.96     4997207
          4          24.82           3.97     4997207
          5          20.15           4.88     4997207
          6          16.97           5.80     4997207
          7          19.25           5.11     4997207
          8          17.16           5.73     4997207
          9          15.42           6.38     4997207
         10          13.94           7.06     4997207
         11          13.01           7.57     4997207
         12          12.05           8.17     4997207
         13          16.93           5.81     4997207
         14          16.47           5.98     4997207
         15          15.76           6.25     4997207
         16          15.72           6.26     4997207
         17          14.62           6.73     4997207
         18          14.58           6.75     4997207
         19          14.47           6.80     4997207
         20          14.20           6.93     4997207
         21          13.86           7.10     4997207
         22          13.89           7.09     4997207
         23          13.57           7.25     4997207
         24          13.55           7.26     4997207
         25          13.21           7.45     4997207
         26          13.33           7.39     4997207
         27          13.28           7.41     4997207
         28          13.44           7.32     4997207
         29          13.69           7.19     4997207
         30          13.75           7.16     4997207
         31          13.56           7.26     4997207
         32          13.58           7.25     4997207
         33          13.31           7.40     4997207
         34          13.33           7.38     4997207
         35          13.11           7.51     4997207
         36          13.43           7.33     4997207

   Best K: 12
   Hardware threads: 12
   K/threads ratio: 1.00
   Best time: 12.05 ms
   Maximum speedup: 8.17x

--- Data size: 50000000 elements ---

1. Sequential count_if (no policy):
   Time: 491.62 ms
   Result: 24995033

2. count_if with execution policies:
   execution::seq: 551.77 ms
   execution::par: 65.68 ms
   execution::par_unseq: 66.06 ms
   Speedup par vs seq: 8.40x
   Speedup par_unseq vs seq: 8.35x

3. Custom parallel count_if (different thread counts K):
          K      Time (ms)        Speedup      Result
   --------------------------------------------------
          1         488.62           1.01    24995033
          2         246.36           2.00    24995033
          3         163.74           3.00    24995033
          4         125.09           3.93    24995033
          5         103.10           4.77    24995033
          6          86.35           5.69    24995033
          7          89.71           5.48    24995033
          8          80.58           6.10    24995033
          9          73.80           6.66    24995033
         10          68.60           7.17    24995033
         11          63.96           7.69    24995033
         12          60.92           8.07    24995033
         13          76.09           6.46    24995033
         14          75.59           6.50    24995033
         15          73.71           6.67    24995033
         16          74.04           6.64    24995033
         17          71.17           6.91    24995033
         18          73.13           6.72    24995033
         19          72.75           6.76    24995033
         20          69.76           7.05    24995033
         21          66.78           7.36    24995033
         22          64.93           7.57    24995033
         23          62.77           7.83    24995033
         24          61.08           8.05    24995033
         25          73.21           6.72    24995033
         26          71.79           6.85    24995033
         27          74.06           6.64    24995033
         28          70.40           6.98    24995033
         29          70.77           6.95    24995033
         30          68.91           7.13    24995033
         31          66.78           7.36    24995033
         32          66.73           7.37    24995033
         33          65.01           7.56    24995033
         34          64.09           7.67    24995033
         35          62.38           7.88    24995033
         36          62.60           7.85    24995033

   Best K: 12
   Hardware threads: 12
   K/threads ratio: 1.00
   Best time: 60.92 ms
   Maximum speedup: 8.07x


=== CONCLUSIONS ===
1. Execution policies (par, par_unseq) show significant speedup
   on large datasets compared to sequential execution.

2. Custom parallel algorithm performs best when K is close to
   the number of hardware threads available.

3. When K exceeds optimal value, execution time increases due to
   thread creation and synchronization overhead.

4. Compilation with /O2 provides significant performance improvement
   compared to /Od (no optimization).

NOTE: For optimization level comparison, compile the program with
      /Od (no optimization) and /O2 (maximum optimization) flags.
```
      
