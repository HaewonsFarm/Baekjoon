# [Ruby III] Sweep Stakes - 23203 

[문제 링크](https://www.acmicpc.net/problem/23203) 

### 성능 요약

메모리: 48360 KB, 시간: 5440 ms

### 분류

자료 구조, 분할 정복, 다이나믹 프로그래밍, 고속 푸리에 변환, 구현, 수학, 오프라인 쿼리, 세그먼트 트리, 정렬

### 제출 일자

2024년 12월 30일 23:14:17

### 문제 설명

<p>You may have already won! In fact, you did already win! You won your very own island, in the deepest reaches of the unexplored ocean! Well, mostly unexplored. As it happens, there was a small military base there before you, and when they packed up and flew out they left behind an assortment of scraps, munitions, tunnels, . . . and unexploded defensive ordnance. That’s right: You now possess your very own minefield.</p>

<p>The minefield consists of an m × n grid, with any square of the grid holding 0 or 1 mines. Fortunately, you were able to recover the engineers’ plans from when they deployed the mines. Unfortunately, the exact locations of the mines were never written down: the engineers had a preselected independent probability of deploying a mine in each square. However, you do know how many mines were placed in total.</p>

<p>You would like to estimate how safe various parts of your island are. Write a program to compute the probability of mine counts over various subsets of the minefield.</p>

### 입력 

 <p>The first line of input contains four integers m, n, t, and q, where m and n (1 ≤ m, n ≤ 500) are the dimensions of the minefield, t (0 ≤ t ≤ mn) is the total number of mines, and q (0 ≤ q ≤ 500) is the number of queries. The second line contains m real numbers p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>m</sub> (0 ≤ p<sub>i</sub> ≤ 0.1 for all i, with at most six digits after the decimal point specified), and the third line contains n real numbers q<sub>1</sub>, q<sub>2</sub>, . . . , q<sub>n</sub> (0 ≤ q<sub>j</sub> ≤ 0.1 for all j, with at most six digits after the decimal point specified). The preselected probability of the engineers placing a mine on square (i, j) is p<sub>i</sub> + q<sub>j</sub>. All choices of whether to place a mine on a given square were made independently, and the value of t is chosen so that the probability of deploying exactly t mines is at least 10<sup>−5</sup>.</p>

<p>Each of the remaining q lines describes a single query. Each of those lines begins with an integer s (0 ≤ s ≤ 500), followed by s pairs of integers i and j (1 ≤ i ≤ m, 1 ≤ j ≤ n), which are the coordinates of s distinct squares in the grid.</p>

### 출력 

 <p>For each query with s squares, output s + 1 real numbers, which are the probabilities of the s given squares containing 0, 1, . . . , s mines. Your answer should have an absolute error of at most 10<sup>−6</sup>.</p>

