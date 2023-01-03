This repository contains source code I wrote and things I learned from
doing daily Topcoder programming competitions from 2013-2015.

I would use this file as a template or knowledge base for looking up
algorithms or solutions. All performance benchmarks and source code
mentioned here is in C++.

Some of the notes relate to typical "programmer interview" questions,
as that is what I was preparing for at the time.


-- Ando Emerencia

======================================================================


int mydiv(int T, int B) {
  if (B>T) return 0;

  int d = B;
  int count = 1;

  while (d*2 <= T) {
    d *= 2;
    count *= 2;
  }

  return (count + mydiv(T-d, B));
}
if a>0, b>0 and c>a+b, then
log a+ log b <= 2 log c -2


The time complexity of the BFS is O(|vertices|+|edges|)

Trial division is exponential in number of bits, but O(sqrt(n)) in just the input number n

Cycle finding alg: Floyd's cycle finder: Tortoise and hare algo.
  # at this point the position of tortoise which is the distance between 
  # hare and tortoise is divisible by the length of the cycle. 
  # so hare moving in circle and tortoise (set to x0) moving towards 
  # the circle will intersect at the beginning of the circle.
  Finds position and length


Integer overflowing: 
  divisible by 3 = d
  M = $base($round($calc((2^33)/3),0),10,16)
  M*d = 1
  I = k*d + s
  M*I = M*k*d + M*s
      = k + M*s  < 0x55555555  // represents 64 bit number when s -- 0


Integer Factorization: No known algorithm that runs in polynomial time for large integers. The commonly used trial division works fast only for small integerse. (O sqrt(n))
GCD: EUclidean algorithm: Euclidean algorithm always needs less than O(h) divisions, where h is the number of digits in the smaller number b. Runs in polynomial time.

Powers of 2
2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 4294967296
1 2 3  4  5  6   7   8   9   10   11   12   13    14    15    16         32

2^64 = 1 with 19 zeros (10^19)

CODE STYLE
  Use the C++ keyword explicit for constructors with one argument. So there's no conversion.
  Your class definition should start with its public: section, followed by its protected: section and then its private: section. If any of these sections are empty, omit them.
  class member variables end with a trailing underscore.
  constants: kMixedCase = 7;
  use spaces between everything
  regular functions have mixed case, start with capital. accessors and mutators match the name of the variable
  ALL_CAPS = macros (#define)
  INT_MAX
  the comment describes the function, it does not tell the function what to do
  Note that you should never describe the code itself. Assume that the person reading the code knows C++ better than you do, even though he or she does not know what you are trying to do.
  no if statement on one line when there is an else
  when else: use braces around both if and else
  80 chars default line length
  do not indent #if #endif directives
  public:/private: sections are indented with 1 space
  wrapped lines indent 4 spaces
  namespaces do not indent
  http://www.cplusplus.com/doc/tutorial/namespaces/



BENCHMARKS
  READ SPEED:: 1/3 of write speed. The append is very slow.
  50k requests per second per computer.
  Sorting 3 million integers on 1 PC takes about a second.
       100.000 : 0.02-0.04s
     1.000.000 : 0.2-0.5s
    10.000.000 : 2-5s
   100.000.000 : 20 sec;
 1.000.000.000 : 200 
4* 2^12
                 100000
                sorting 1 trillion integers takes a day on 1 pc
                1 trillion integers = 4TB memory
                1 billion integers  = 4GB memory
                1 million integers  = 4MB memory

Sum 1/(n!) sums up to e
n! asymptotic is (n^n)/(e^n)

int a = 23947923;

p&(p-1) 

Take the log of it



There is an array A[N] of N numbers. You have to compose an array Output[N] such that Output[i] will be equal to multiplication of all the elements of A[N] except A[i]. For example Output[0] will be multiplication of A[1] to A[N-1] and Output[1] will be multiplication of A[0] and from A[2] to A[N-1]. Solve it without division operator and in O(n).
vector<int> array_multiplication(vector<int> a) {
  vector<int> b(a.size(),1);
  int l=1;
  int r=1;
  for (int i=0;i<a.size();++i) {
    b[i]*=l;
    b[a.size()-1-i]*=r;
    l *=a[i];
    r *=a[a.size()-1-i];
  }
  return b;
} works because for each one you're coming once from the left and once from the right



SORTING:
  3 million takes about a second
    100.000 : 0.02-0.04s
  1.000.000 : 0.2-0.5s
 10.000.000 : 2-5s
 1 billion: 3 to 10 minutes?
 1 pc does about 100 milion each
 1 million strings of 100 Bytes is about 100 MB
  takes 0.4 seconds to sort a million integers (14 ticks on counting sort nonstable)
  numbers:
    if you know they fall in a certain range: counting sort (stable or nonstable), O(n+k) space, O(n+k) time
    otherwise: radix sort (only one version, stable): uses O(n) space, O(n*k) time  k is max key length
    else: merge sort, heap sort or quick sort
    quick sort has a quadratic time worst-case complexity.
    heap sort is in place bottom up heap O(n), sorting O(n log n)
    quick sort also in place, although it uses O(log n) space for the call stack
    merge sort uses O(n) space, O(n log n) time
  Dutch flag sort (three way sort):
   void threeWayPartition(int data[], int size, int low, int high) {
     int p = -1;
     int q = size;
     for (int i = 0; i < q;) {
       if (data[i] == low) {
         swap(data[i], data[++p]);
         ++i;
       } else if (data[i] >= high) {
         swap(data[i], data[--q]);
       } else {
         ++i;
       }
     }
   }
!!! difference between hashmap and hashtable <-- hashtable is synchronized, hashmap is not. hashtable does not allow null values or keys.
!!! max submatrix:
typedef struct info{int i; int j; int max;} info;

int row(int** a, int i,  int j1, int j2) {
  int s = 0;
  for (int j = j1; j <= j2; j++) s += a[i][j];
  return s;
}


. . .
. (n-1)
N! 

int column(int** a, int j, int i1, int i2) {
  int s = 0;
  for (int i = i1; i <= i2; i++) s += a[i][j];
  return s;
}

void max_matrix(int** a, int n) {
  info** p = new info*[n];
  for (int i = 0; i < n; i++) p[i] = new info[n];
 
  info max_info = {0, 0, a[0][0]};
  int max_i = 0;
  int max_j = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
       p[i][j] = (info){i, j, a[i][j]};
       if (i > 0) {
          info up = p[i-1][j];
          up = (info){up.i, up.j, up.max + row(a, i, up.j, j)};
          if (up.max > p[i][j].max) p[i][j] = up;
       }
       if (j > 0) {
          info left = p[i][j - 1];
          left = (info){left.i, left.j, left.max + column(a, j, left.i, i)};
          if (left.max > p[i][j].max) p[i][j] = left;
       }
       if (max_info.max < p[i][j].max) {
           max_info = p[i][j];
           max_i = i;
           max_j = j;
       }
    }
  }
  printf("The submatrix starts at (%i, %i) and ends at (%i, %i) and the sum is %i", max_info.i, max_info.j, max_i, max_j, max_info.max);
  for (int i = 0; i < n; i++) delete[] p[i];
  delete[] p;
}


Also the triangle area can be described using cross product.
!!! how to do left turn  cross product 3 dim it's: a[1]*b[2]-b[1]*a[2]  a[2]*b[0]-b[2]*a[0]   a[0]*b[1]-b[0]*a[1]
!!! in 2 dims: if something lies left of a line or inside a polygon:
  bool left_of_line(point p, vector<point> l) {
    point ld; // actually a direction
    ld.first = l[1].first-l[0].first;
    ld.second = l[1].second-l[0].second;
    int d = ld.first*(p.second -l[0].second) - ld.second*(p.first - l[0].first);
    return d > 0;
  }
!!! how congestion works in the tcp protocol http://en.wikipedia.org/wiki/TCP_congestion_avoidance_algorithm
  <-- TCP maintains a congestion window, limiting the total number of unacknowledged packets that may be in transit end-to-end
!!! Tree search algorithms
  DFS: you mark em when you enqueue em.
    when dequeueing: first check if it is what we are looking for, if not: then check outgoing unmarked edges.
  Dijkstra: single source, shortest path DFS in weighted graph, O(|E|+|V|log|V|) performance. Dijkstra does not handle negative weights.
  Bellman-Ford: can be used for shortest path instead of Dijkstra. Slower, but works with negative weights. O(|V||E|) performance. Can detect negative weight cycles if after |V|-1 iterations there are still updates.
 
The bigger the range of the numbers to be sorted becomes, the better counting sort becomes, compared to radix sort. JUST USE COUNTING SORT IT CAN BE PARALELLIZED

COUNTING SORT O(n+r) r = range of numbers to be sorted
  is not in place <-- it can be, but then it is not stable.
  useful when the integers are in a small range
  can be parallellized (different ranges)

RADIX SORT O(n*k) k = max nr digits
  LSD version: least significant digit (right one) first, MSD last.
  O(n*k) for n keys with k or fewer digits
  It is counting sort per digit. regrouping and every time moving up a significant digit

BINOMIAL DISTRIBUTION -- discrete
  represents the sum of a set of random variables with probability p.
  variance np(1-p)
  mean np
  probability mass function   (n choose k) * p^k * (1-p)^(n-k)
  Chernoff bounds: sum of n independent Bernoulli random variables is 
     S = (n choose i) p^i (1-p)^(n-i)
     S has lower bound  1-e^(1/(2p) n (p -1/2)^2   1-e^-n
     P (S <= n/2) = e^-1/(2p) n (p-1/2)^2
     
CENTRAL LIMIT THEOREM
  Sum of random variabels is normally distributed.

POISSON DISTRIBUTION (pwazzon) - discrete about RATE
  Poisson distribution is a discrete probability distribution that expresses the probability of a given number of events occurring in a fixed interval of time and/or space if these events occur with a known average rate and independently of the time since the last event.
  Predicts the degree of spread around a known average rate of occurrence.

EXPONENTIAL DISTRIBUTION - continuous analogue of geometric distribution
  It describes the time between events in a Poisson process, i.e. a process in which events occur continuously and independently at a constant average rate. It is the continuous analogue of the geometric distribution.
  So when lambda = time between events = 4, Poisson distribution will give the probability that an event occurs at time x. Exponential distribution will give probability that event occurs around 
  Expected value is 1/lambda: When you receive phonecalls at a rate of 2 per hour, you can expect to wait 30 minutes between calls.
  Exponential distribution with lambda is 0.5 will have 50% of area to the left of x=2 and 50% to the right of x = 2.
  Variance : lamba^-2
  mean:  1/lambda
  lambda should be count(highest) / 8.3 trillion

CHI-SQUARED DISTRIBUTION - continuous (special instance of Gamma, sum of squared standard normal random variables)
  Chi-squared distribution with k degrees of freedom is the distribution of a sum of the squares of k independent standard normal random variables.
  Special instance of gamma distribution.
  The chi-squared distribution is used in the common chi-squared tests for goodness of fit of an observed distribution to a theoretical one, the independence of two criteria of classification of qualitative data, and in confidence interval estimation for a population standard deviation of a normal distribution from a sample standard deviation.

GAMMA DISTRIBUTION - continuous (sums exponential variables)
  For instance, in life testing, the waiting time until death is a random variable that is frequently modeled with a gamma distribution.
  If k is an integer, then the distribution represents an Erlang distribution; i.e., the sum of k independent exponentially distributed random variables, each of which has a mean of ? (which is equivalent to a rate parameter of 1/?)

STUDENT'S T DISTRIBUTION
  is a family of continuous probability distributions that arises when estimating the mean of a normally distributed population in situations where the sample size is small and population standard deviation is unknown. It plays a role in a number of widely used statistical analyses, including the Student's t-test for assessing the statistical significance of the difference between two sample means, the construction of confidence intervals for the difference between two population means, and in linear regression analysis.
  
  Student's t describes a sample of a distribution. If you have the whole distribution, then you'd use a Gaussian to model that.

Binomial Coefficient (n over k)
  = n!/(k!(n-k)!)
  any set of n elements, the number of distinct subsets containing k elements
  long long bico3(int n,int k) {
	if (k < 0 || k > n) return 0;
	if (k > n-k) k = n-k;
	long long p = 1;
	for (int i=0;i<k;i++) {
	  p = ((n-i)*p)/(i+1);
	}
	return p;
  }

Prime factors by trial division // $calc(2^3*7^5*11^2*13^5)
  vector<int> prime_factors(long long n) {
    vector<int> r;
    for (int i=2;i*i<=n;i++) {
      while (n%i == 0) {
        r.push_back(i);
        n/=i;
      }
    }
    if (n > 1) r.push_back(n);
    return r;
  }


Answers:
- cookies server Set-Cookie: name=value   response Cookie: name=value
- multithreaded programming: execution can be interrupted by context switches so it appears as if multiple threads are running in parallel.
- If you have 1 million integers, how would you sort them efficiently? (modify a specific sorting algorithm to solve this) <---- modified in-place counting sort. radix sort
- In Java, const is static final
- What is the C-language command for opening a connection with a foreign host over the internet? <-- you'd need a socket first. socket.connect

!!! How do you find out the fifth maximum element in an Binary Search Tree in efficient manner. Note: You should not use use any extra space. i.e sorting Binary Search Tree and storing the results in an array and listing out the fifth element. <----------- reverse inorder (right brance, node, left branch) stop a the node that was visited 5th (need a global var)

!!! implement hashtables
!!! 2^64 = 18 446 744 073 709 551 616

!!! binary trees (at least one flavor of balanced: red-black, splay or avl), n-ary trees and trie-trees. know how they are implmented. BFS/DFS, postorder/preorder
!!! graphs (objects,pointers, matrix, adjacency list). familiarize yourself with each representation and pros and cons. Dijkstra and A*. Try to solve with graphs first.
!!! traveling salesman/knapsack: np-complete. be able to recognize.
!!! essentials of combinatorics and probability. be familiar with n-choose-k problems and their ilk.
?? sizeof struct question
!! When the order doesn't matter, use something that tracks whether you have it: KEEP STATES.. You have a finite amount of characters.

Sizeof struct question: it rounds to the next power of 2, where:
  a char takes 1 byte
  a char* takes 4 bytes <--- BECAUSE IT'S ADDRESSED in 32 BIT MEMORY
  long long takes 8 bytes (64 bit)
  int takes 4 bytes     (32 bit)
  int* takes 4 bytes
There is a linked list of numbers of length N. N is very large and you don’t know N. You have to write a function that will return k random numbers from the list. Numbers should be completely random. Hint: 1. Use random function rand() (returns a number between 0 and 1) and irand() (return either 0 or 1) 2. It should be done in O(n). Reservoir Sampling.
void select(list* l, int* v, int n) {
  int k = 0;
  while (l != NULL) {
    if (k < n) {
      v[k] = l->val;
    } else {
      int c = rand() % (k + 1);  // or if rand between 0 and 1, rand() < n/k
      if (c < n) v[c] = l->val;
    }
    l = l->next;
    k++;
  }
}   n^(1/k)  -> will approach 1 for any n between 0 and 1 if k is increasing.
Can we break up the reservoir sampling?
. Find or determine non existence of a number in a sorted list of N numbers where the numbers range over M, M >> N and N large enough to span multiple disks. Algorithm to beat O(log n) bonus points for constant time algorithm.
Cannot be done in constant time only probabilistic approach.
Give a fast way to multiply a number by 7. (n<<3)-n
Test if integer is power of 2:
  x>0 && ((x-1)&x) == 0, or
  x>0 && (x&(-x)) == x
Spiral numbers in constant memory
  int spiral_seq(int x, int y) {
	if (x==y && x>=0) return ( (2*(x+1)-1) * (2*(x+1)-1) );
	if (y>0 && -y<=x && x<=y) return ( spiral_seq(y-1, y-1) +y-x );
	if (x<0 && x<=y && y<=-x) return ( spiral_seq(x, -x) -x-y );
	if (y<0 && y<=x && x<=-y) return ( spiral_seq(y, y) +x-y );
	if (x>0 && -x<=y && y<=x) return ( spiral_seq(x, -x) +y+x );
	else fprintf(stderr, "Error, logical in spiral_seq(%d, %d)\\n",x,y);
  }


24*3600 = 86400 seconds in a day.

difference hashtable/hashmap? <-- hashtable synchronized, hashmap not. hashtable does not allow null keys or values, hashmap does allow one null key and any number of null values. 

Catalan numbers: parentheses, no more Xs than Ys, Cn = nr of Dyck words of length 2n. Also: It follows that Cn is the number of full binary trees with n + 1 leaves:
long long catalan_numbers(int n) {
  vector<long long> a(n+1,0);
  a[0] = 1;
  for (int i=1;i<=n;++i) {
    for (int j=0;j<i;++j) {
      a[i]+=a[j]*a[i-j-1];
    }
  }
  return a[n];
}

BASE: (digit)*base^(position before or after decimal)

int mult7(uint n) { return ((n<<3) - n); }  //probably the one they want

Algorithms Book:
Big-Oh notation:
  Big oh is an upper bound
  there is some integer n_0 >= 1 that the function is never larger than some constant times O(...), for all n > n_0
  Big-Oh is not a strict bound. i.e., something that is O(n^2) is also O(n^3).
  Big O in its definition already has the less than or equal a constant times ...
  log(n^2) = O(log n)
  Logarithmic: O(log n)
  linear: O(n)
  quadratic: O(n^2)
  polynomial: O(n^k) (k>=1)
  exponential: O(a^n) (a>1)
  Big-Omega: inverse Big-Oh
  Big-Theta: Big-Omega and Big-Oh. Allows us to say two functions are asymptotically equal, up to a constant factor.
  Tractability: difference between polynomial and exponential-time algorithms
  little oh: less than
  little omega: greater than
  functions ordered by growth rate: log n < log^2 n(=(log n)^2) < sqrt(n) < n < n log n < n^2 < n^3 < 2^n
  n! asumptotic behavior = (==> n^n / e^n )
Summations:
  Sum(a^i), i = 0 to n inclusive is (1-a^(n+1))/(1-a)
  1+2+4+8+ 2^(n-1) = 2^n -1
  for any integer n>=1, sum i from i = 1 to n is n(n+1)/2
Logarithms and exponents:
  log_b a = (log_c a)/(log_c b)
  log_b a^c = c * log_b a
  b^(log_c a) = a^(log_c b)
  (b^a)^c = b^(a*c)
  b^a * b^c = b^(a+c)
  b^a / b^c = b^(a-c)
  log^c n = (log n)^c
  log log n = log(log n)
Probability
  two events are independent if you can multiply their possibilities
  conditional prob: Pr(A|B) = Pr(A n B) / Pr (B)
  this is the prob of A occurring, given that B occurs. which is P(A) if events are independent
  Chernoff bounds are used to bound the sum of a set of random variables
Amortization/Average running time
  Where you realize there is an upper bound on the number of times you execute an action. Not included in O notations.
  Under the assumption that every time you extend the array you have to copy the values.
  
String matching multiple strings: suffix tree:: longest common substring

Data structures
Stacks: LIFO
  t points to index of top element on stack (if stack in array), initially to -1
Queue: FIFO
  implementation: f (front) and r (rear)
  f points to first elem in queue
  r points to next available index in queue
  always check limits for every operation
Stacks & Queues: Probably linked list structure is best since you remove items (otherwise you waste space)
  array-based implementation: advantage: operations in O(1) (=constant) time
  disadvantage: need to know size in advance, may waste memory if not all items used
  Round-robin scheduling can be implemented by putting all ready processes in a queue. popping it from the queue when processing, and putting it back in the queue when done.
Vectors, Lists, and Sequences:
  vector: linear sequence that supports access to its elements by rank.
    rank = nr of elements preceding.
    insertAtRank and removeAtRank have O(n), rest has O(1) (size,isempty, elemAtrank, replaceAtRank)
    space is O(N), N the size of the array
  list: WHEN YOU REMOVE ITEMS
    when you have a list, atRank, rankOf, elemAtRank, replaceAtRank operations cost O(n) compared to array like implementation.
    removing elements now takes O(1) compared to O(n) for array
    list is faster than array for insertafter element or insertbefore element and REMOVE
  sequence:
    = vector + list

Trees:
  each element has a parent, zero or more children, and a root
  a node without children is called a leaf node
  Preorder: small to big (do action before doing it on all children). Example: sections in a document O(n)
  Postorder: big to small (do action after doing it on all children) O(n) Example: size of a directory if it includes the directory size and size of children
  in order: (only for binary trees) left first, then node, then right <-- use this to print sorted nodes O(n)
  In-order reverse: is from big to small
  Euler tour combines preorder, inorder and postorder traversal. Used for example for printing a parenthesis before, in between and after each node. (only print parenthesis when it has child nodes).
Binary Trees
  level d = set of nodes at the same depth d. level 0 has 1 node, the root.
  in proper binary tree:
    - number of leaf nodes is at least h+1 at most 2^h
    - number of internal nodes at least h, at most 2^h -1
    - total number of nodes at least 2h+1 at most 2^(h+1) -1
    - height at least log(n+1) -1, and at most (n-1)/2
    - #leaf is 1 more than #internal
  Storing a tree in a vector: vector (fast, simple, space inefficient, harder if you want to remove items, positions,elements O(n), everything else O(1), worst case N = array size = O(N) (size of array), 2^((n+1)/2) or linked structure, or heap tree (N = n+1)
    p(root) = 1
    p(u.left) = 2*p(u)
    p(u.right) = 2*p(u)+1
    traversal would be breadth first
  Storing regular binary tree in vector (unbalanced) has worst case exponential space requirement
  Storing a tree in a linked list <-- space requirement O(n)
    Store size and root node separately
    works for general trees
    again positions/elements O(n), rest O(1), children O(cv) number of children
Priority Queue:
  can be implemented as unsorted sequence (insert/remove fast), sorted sequence (min/removeMin fast, insert slow), or heap(min fast, rest is log n max)
  key = weight, rank
  keys have total order:
    reflexive k<=k
    antisymmetric if k1<=k2 and k2<=k1 then k1=k2
    transitive k1<=k2 k2 <=k3 k1<=k3
  pop item with smallest key
Selection Sort:
  take minimum and remove it
  priority queue sort.
  O(n^2) time because the priority queue isn't sorted and you have to find the minimum element every time.
Insertion Sort
  maintain a sorted sequence. but dumbly
  O(n^2) time (best case O(n) for reverse order)
Heap: efficient way to implement a priority queue
  priority queue efficient for both insertion and removals (O(log n))
  HEAP ORDER PROPERTY: for every node v other than the root, the key stored at v is greater than or equal to the key stored at v's parent
  so root is minimum node.
  root is called level 0.
  Complete Binary Tree: if all but the last level is full and last level has all internal nodes to the left of external nodes
  last node is significant (rightmost deepest internal node)
  can be implemented in vector
  INSERTION: insert elem at end of heap, then do upheap bubbling (swap as long as child < parent)
  can also be with linkedlist but harder
  DOWN-HEAP BUBBLING is O(log n), up-heap bubbling is O(log n)
  REMOVEMIN: remove root, move last node to root, down-heap bubbling.
  down-heap bubbling: swap node with child node that has smallest size
  REMEMBER: heap doesn't sort everything right away, only minimum element is guaranteed. you need to remove (op log n) to get next smallest element
  insertItem O(log n), removeMin O(log n)
  ! if first elem is at 0 instead of 1, use 2k+1 and 2k+2 
Heap Sort O(n log n)
  also has an inplace version where you put the max at the top.
  INPLACE Heap Sort: create a reverse heap starting at idx 0 (so 2k+1 and 2k+2 and (k-1)/2). then insert elems 0 to size.. with down-heap bubbling.
  then removeMax every time and putting it at the end of the array so going size to 0.
  with downheap bubbling
  ! Heap construction takes O(n log n) time, can also be done in O(n) if all values are
  given in advance. called BOTTOM-UP HEAP CONSTRUCTION  (CAN be done with vector though) == heapify
Locator: LIKE a coat check. When item gets moved around, you can still find it with locator.
When elements in a collection are unique (unique keys) then you can use keys as address locations. That's why there is a distinction. There can be multiple (i.e., different) elements that have the same key.
Dictionary: == Key,Value store. Special case where key == value
  Sentinel: NULL (no such key)
  Naive: unsorted sequence (log file/audit trail). For small data or data that is unlikely to change
Hash Table: O(n) worst case, O(1) expected/average time for search/insert/delete
  each key has a unique element
  Two major components:
    Bucket Array
      holds NULL values for all keys not in array.
      indexed by keys
      collision: two elements mapped to the same bucket
      can be wasteful space
    Hash function
      returns an integer (called hash code/hash value)
      good hash function: minimize collisions, fast/easy to compute
      hash code converted to compression map (= index range of bucket array) via mod(abs)
      polynomial hash code with a = 33 (different powers of)
      alternative to mod: MAD (multiply add divide)
      h(k) = |ak+ b| mod N , a,b random with a mod N != 0
  Handling collisions
	Separate Chaining: Just linear search in the buckets
	Open addressing: Just one element per bucket
	  Linear probing: store it in the next empty bucket
		removeElement would be more difficult
		can replace it with a "deactivated item" object, which you would replace when adding a new object.
	  Quadratic probing. leave space between. Every time add j^2 to the value. If N is not a prime, then quadratic probing may not find an empty bucket in A even if one exists. If N is prime and bucket is at least half full, may also fail to find a bucket.
	  Double Hashing: A[f(k)] A[(f(k) + j * h(k))%N] h(k) = q - (k mod q) j = 1,2,3
	  USING A hash function because if you use a polynomial hash function and the constant used in that and the bucket size are not coprime then the things with same first character are equal mod BIGGEST common factor
  Universal Hashing
    Pr(h(j) == h(k)) <= 1/N  -- 2-universal familiy of hash functions
    It's less if M < N (i.e., not all buckets used)
    Universal hash function: h(k) = ((a*k + b) mod p) mod N, with p a prime bigger than the number of inputs but < 2 times that number
    causes order all operations to have a running time O(ceil(n/N)) = O(n) with a constant determined by load factor


Amortization
  Used for understanding running times of algorithms that have steps with widely varying performance.
  It is a worst-case way for performing an average-case analysis.
  AMORTIZED RUNNING TIME: of an operation within a series of operations as the worst-case running time of the series of operations divided by the number of operations.
  When you average over multiple operations.
  Amortized running time for an operation may be much lower than actual running time for an operation (it is an average).
  Note that O() bounds are not strict. So with amortization you can get an O() bound that is closer to the actual bound of the algorithm(?)
  When you execute n operations, and one of the operations costs O(n) time, and the other O(1) time.: Total of items you remove cannot be larger than total amount of items you add.
  Telescoping sum: all terms other than the first and the last cancel each other out.
  Potential Functions: call the cyberdollars potential
  Extendable array: when you increment it by a fixed amount instead of doubling, amortized running time of a push operation is O(n) instead of O(1). Because you need to increment it every n/c steps.


3: Search Trees and Skip Lists
==============================
Binary search trees do not ensure efficient worst-case performance (O(n)).
AVL tree: logarithmic time search and updates.
Bounded-depth trees: All external nodes at same (pseudo-)depth. Red-Black tree. Advantage Red-Black tree has over other trees (including AVL) is that update operations after insertion or removal take only O(1) rotations.
Splay trees are attractive due to simplicity of search and update methods. Splay tree adapts to queries, moves used/requested nodes higher up in the tree.
Skip List: like tree but with probabilistic depth bounds. Simple operations.

Binary Search Tree
  DEFINITION: All elements in left subtree of node are <= elem at node, all elems in right subtree are > elem at node.
  used for implementing ordered key/value stores (order in keys)
  elems are not necessarily unique(?)
  Determine if a certain key is in a binary search tree: binsearch
  Binary search operates on a sorted array (=lookup table) Space O(n), insert/remove O(n) (if implemented in array), findElement/closestKeyBefore O(log n)
  removeElement runs in O(h), even for unbalanced search tree (note that h != log n in that case)
  Traversal: O(h+n)

AVL Trees
  AVL trees are more rigidly balanced than red-black trees, leading to slower insertion and removal but faster retrieval.
  HEIGHT-BALANCE PROPERTY: for every internal node v of T, the heights of the children can differ by at most 1
  Any tree that satisfies this property is called an AVL tree
  height of a node is the length of longest path to external node  1+max(height(l),height(r))
  Height of AVL tree is O(log n)
  Update Operations
    Insertion
      Only restructure if the inserted node has at least a parent and a grandparent
      z = first unbalanced node
      y = child of z with largest height
      x = child of y with higher height (if there is a tie, choose x to be an ancestor of w)
      <trinode restructuring>
      rename x y z to a b c so that a <= b <= c
      replace z with b
      make a and c children of node b
      make four previous children of x y z (other than x and y) the children of a and c
   Removal
     remove according to binary tree
     then call restructure method as long as we find something unbalanced
  Find, insert, and remove take O(log n) 

Bounded-Depth Search Trees -- RBTree slower retrieval than AVL, but faster insert/remove
  Multi-Way Search Trees
    all external nodes have no value
    each node has at least two internal nodes, internal nodes are soretd
    (2,4) Tree:  balanced multiy-way tree
      Size property: Every node has at most four children
      Depth property: All the external nodes have the same depth
      Depth = Theta(log n)
  Red-Black Trees: complicated but only constant number of trinode restructurings needed after an update to restore balance
    Root property: the root is black
    External property: Every external node is black
    Internal property: The children of a red node are black.
    Depth property: All external nodes have the same black depth, which is defined as the number of black ancestors minus one.
    Can be transformed into (2,4) trees and back
    The height of a red-black tree storing n items is O(log n).
    Space requirement O(n).
    Searching takes O(log n) time.
    Insertion:
      Insert new node like normal bintree. Color black if root, otherwise color red.
      Can lead to a double red.
      Case1: sibling of middle node is black:
        restucture like with AVL tree, color highest black and its two children red.
      Case2: sibling of middle node is red:
        recoloring: color middle node and top node black and their parent red (unless the parent is the root, in which case it stays black)
        possible that coloring the parent red creates another double red case which has to be resolved in one of the ways.
    Insertion in RB tree can be done in O(log n) time and requires at most O(log n) recolorings and 1 trinode restructuring.
    Insertion simplified:
      - Color new node Red
      - insert_case1  if (n->parent == NULL) color black else case2
      - insert_case2  if parent == black stop else case3
      - insert_case3  if uncle is red, color uncle black, color parent black, color grandparent red, insertcase_1(grandparent) else insert_case4
      - insert_case4  trinode restructuring optional no coloring, change n to n->left if left rot, n->right if right rot (so n is lowest node again)
      - insert_case5  trinode restructuring color parent black, color grandparent red, if n == n->parent->left rotate_right(n->parent) else rotate_left(n->parent)
    Removal
      Remove like bin tree.
      Replace node with child, color black if either node or child were red.
      If both node and child were black, new node has double black.
      O(log n) time , performs O(log n) recolorings and 1 adjustment + 1 trinode restructuring (= 2 restructure ops)
      Three cases:
        Sibling y of r is black and has a red child z
          trinode restructuring on z and its two closest ancestors
          color top whatever color top previously had, color its children black, and color the double black node black.
          Done after one restructuring
        Sibling y of r is black and both children of y are black
          Recoloring: color r black, y red and color x black if it was red, otherwise color it double black. (and propagate)
        Sybling y of r is red
          adjustment operation
          after adjustment, we are at case 1 or case 2
    Removal simplified:
      - if node n->left != NULL and n->right != NULL then r is n->right, while r->left != NULL r = r->left; n->val = r->val; n = r;
      - delete_one_child(n): find a child if there is any,
        if there is none, call delete_case1(n)
        replace_node(n,c)
        if (n == Black) then color c-> Black if it is not null and call delete_case1(c)
      - delete_case1  if (n != NULL && n->parent != NULL) delete_case2(n) 
      - delete_case2  n is black but sibling is red: parent red, sibling black, then push n further down by rotation
      - delete_case3  if sibling and both children of s are black: color s red, if parent is black, delete_case1(parent), else  color parent black
        if not then delete_case4
      - delete_case4 if sibling is black (trivial) (and has a red child): 
        if n is left child and s->right is null or black (meaning the other child of s is red): color s red, color s->left black, rotate_right(s)
        else if n is right child and s->left == null or s->left is black: color s red, color s->right black, rotate_left(s)
      - delete_case5  color s like parent, color parent black
        if n = left child, color s->right black, rotate_left(s)
        else, color s->left black, rotate_right(s)

Splay Trees Theta(n) worst-case performance for search/insert/delete
  No explicit rules to enforce balance.
  Applies a move-to-root operation called splaying after every access to keep the tree balanced in an amortized sense.
  Splay before or after deleting a node. Before is easier.

B-Trees
  B-Tree is an effective method for storing a dictionary in external memory.
  A B-Tree of order d is simply an (a,b) tree with a = ceil(d/2) and b = d.
  (a,b) trees:
  size property:
    In (a,b) trees, every node has at least a children (unless it's the root), and at most b children.
  depth property:
    All the external nodes have the same depth.
  Height of an (a,b) tree storing n items is Omega(log n/log b) and O(log n/log a).
  Unlike self-balancing binary search trees, the B-tree is optimized for systems that read and write large blocks of data. It is commonly used in databases and filesystems.
  A B-tree is kept balanced by requiring that all leaf nodes be at the same depth. 
  Have the child nodes fit into a block. Useful when the cost of processing the data is less than the cost of retrieving it.
  Create an index to indicate location in blocks: In practice, if the main database is being frequently searched, the aux-aux index and much of the aux index may reside in a disk cache, so they would not incur a disk read.
    keeps keys in sorted order for sequential traversing
    uses a hierarchical index to minimize the number of disk reads
    uses partially full blocks to speed insertions and deletions
    keeps the index balanced with an elegant recursive algorithm

External-Memory Sorting
Multi-Way Merge-Sort
  Merge many recursively sorted lists at a time, reducing the number of levels of recursion.

Bucket sort is LSD radix sort



Graph Algorithms
================
Graphs store connectivity information. Which objects are connected to others.
Edges can be directed or undirected. If edge (u,v) is directed, meaining there is an arrow from u to v.
  Directed edge: asymmetric relation
  Undirected edge: symmetric relation
Undirected graph: all edges in graph are undirected.
Directed graph: (digraph) all edges directed.
Mixed graph: both directed and undirected edges.
vertices of an edge are called end vertices or end points of that edge. If directed: origin and destination.
ADJACENT VERTICES: if they are connected by an edge (endpoints of the same edge)
INCIDENT: an edge is incident on a vertex if the vertex is one of the edge's endpoints.
outgoing edges of a vertex: directed edges whose origin is that vertex
incoming edges of a vertex: directed edges whose destination is that vertex
degree of a vertex: deg(v) = #incoming + #outgoing edges. indeg(v) and outdeg(v).
parallel edges/multiple edges: doubles (i.e. edges is a collection, not a set. a collection can have doubles, a set cannot).
self-loop: the two end points of an edge are the same
SIMPLE GRAPHS: no parallel edges or self-loops. the edges of a simple graph ARE a set of vertex pairs.

Properties of graphs
  Sum(v in G) deg(v) = 2*m // m number of edges (undirected graph)s
  For digraph: Sum(v in G) indeg(v) = Sum(v in G) outdeg(v) = m  (all edges have to be directed)
  Undirected simple graph: m <= n(n-1)/2  ( n(n-1) for directed). So simple graph with n vertices has O(n^2) edges
PATH: starts and ends at a vertex. with edges and other vertices in between.
CYCLE: path with same start and end vertices.
SIMPLE PATH: each vertex in the path is distinct (i.e., it contains no cycles).
SIMPLE CYCLE: each vertex in the path is distinct except for first and last.
DIRECTED PATH: all edges are directed and traversed along their direction (any path in a directed graph is directed. you can't have directed paths in undirected graphs, but you can have directed paths in mixed graphs).
DIRECTED CYCLE: a cycle such that all edges are directed and traversed along their direction.
SUBGRAPH: vertices and edges of subgraph H are subsets of vertices and edges of G. Any route you take in H you can also take in G. It doesn't add edges or vertices.
SPANNING SUBGRAPH: Contains all the vertices of original graph.
CONNECTED GRAPH: for any vertices v and u, there is a path v->u in the graph.
  ?? What about directed graphs? if there is a path u->v but not v->u, is it still a connected graph?
CONNECTED COMPONENTS: the maximal connected subgraphs of a non-connected graph.
  ?? Can one vertex occur in multiple connected components?
FOREST: graph without cycles. Can also occur in undirected graphs.
                         / - \
                       /       \
                      a          b     <-- with all directed edges is not a cycle.
                        \       /
                          \ - /
TREE: a tree is a connected forest, i.e., a connected graph without cycles. So some forests are trees. Or put another way: some forests consist of a single tree. Others consist of multiple trees.
  In the context of graphs, A TREE HAS NO ROOT (these are free trees (vs rooted trees))
SPANNING TREE: a spanning tree of a graph is a spanning subgraph that is a free tree. has n-1 edges.!!!!!
  - MST with disjoint set forests takes O(n log n) otherwise O(m*n)
  - contains all vertices
  - is connected
  - has no cycles (paths with same start and end point)
  - means if you remove one edge, you no longer have a connected graph. The term "minimum spanning tree" relates to edges having a weight and then choosing the spanning tree that has minimum total weight.
  ?? a directed tree does have a root?
Properties of undirected graph G with n vertices and m edges
  if G is connected then m >= n-1
  if G is a tree then m = n-1 (just means no cycles)
  if G is a forest then m <= n-1 if m < n-1 then graph is not connected. if m = n-1 then it is also a tree.
Graph ADT methods
  Have a method that returns a vertex of the graph (since there is no root vertex).
  A Vertex should have a type T to store an object value
  An Edge should have a type W to store an object weight, and an origin Vertex and a destination Vertex. Maybe a bool for isdirected.
  ! When you remove a vertex you have to remove all its incident edges.
Data Structures for Graphs (3 notations what are their tradeoffs and complexities)
  All representations use a container to store the vertices of a graph.
  Edge List and Adjacency list use O(n+m) space, Adjancency Matrix uses O(n^2) space.
  Edge List (Possibly simplest, not most efficient) (memory use: O(m+n))
    Advantage: fast access from Edge to its vertices.
    Disadvantage: slow access from Vertex to its Edges (requires search through all edges)
    all vertices stored in a container
    Vertex has:
      - T val (can also be name)
      - int nr incident undirected edges
      - int nr incoming directed edges
      - int nr outgoing directed edges
      - index into the vertex array where it is stored
    Edges explicitly represented by Edge objected. stored into a container E.
      - W weight (can also be name)
      - bool directed
      - Vertex<T> origin
      - Vertex<T> destination
      - index into the edge array where it is stored
    Performance: Everything in O(1) except removing a vertex or finding incidentEdges or adjacentVertices. Those operations take O(m)
  Adjacency List (memory use: O(m+n))
    = Edge List + vertices keep track of their incident edges
    Advantage: faster operations from vertices to edges. finding incident edges or adjacent vertices for a vertex is proportional to output size. removing a vertex is faster too because you have the edges. ADJACENCY LIST is superior in space and time to adjacency matrix for everything except the areAdjacent method.
    Disadvantage: More difficult to implement than edge list
    every vertex also has incidence containers with refs
    Vertex
      also stores references to edges in incidence container
    Edge
      holds references to positions of edge in incidence containers
      (every edge is in two incidence containers)
    If a graph is a mixed graph, every vertex has 3 incidence containers. in, out, and undirected.
  Adjacency Matrix
    Advantage: Determine adjacencies between pairs of vertices in constant time.
    Disadvantage: O(m^2) memory usage. AdjacentVertices or incidentEdges now take O(n) time instead of O(deg(v)) time.
    The array stores references to the edge, or NULL.
    Extends edge list:
    Vertex has:
      - index into matrix
    If edge is undirected, matrix stores reference to same edge in a[i][j] and a[j][i].
    Keep a matrix with references to edges.

DEPTH-FIRST SEARCH O(m_s) time in adjacency list structure (incidentEdges needs to take O(deg(v)) time.
  used for: finding a path between two vertices, determining whether or not a graph is connected, and computing a spanning tree of a connected graph, finding a cycle or reporting a graph has no cycles.
  DFS in UNDIRECTED GRAPH applies the backtracking technique. visits all nodes in the connected component of s.
    start at s. paint s visited.
    consider an arbitrary edge u,v
    if v is visited, back to u.
    if v is unvisited, u = v;
    paint u as visited.
    eventually get to a dead end: all vertices all vertices indicent already visited.
    then backtrack to previous node.
    procedure ends when we are back at s and s has no more unexplored vertices.
  The edges where you unroll the string (the edges that you traverse to get to new nodes = the discovery edges) form a spanning tree of the graph. (back edges lead to already discovered nodes).
  Each back edge implies a cycle in G, consisting of the discovery edges from u to v plus the back edge (u,v).
  Label the edges during DFS as discovery or back to create a spanning tree (all starting at unexplored).
  Recursive implementation does implicit backtracking.

SEPARATION EDGE: edge whose removal disconnects a connected graph G.
SEPARATION VERTEX: a vertex whose removal disconnects G.
These edges and vertices correspond to single points of failure in a network.
Biconnected component if there are two paths between each pair of nodes sharing no common edges or vertices except start and end, i.e., there exists a simple cycle between each pair of nodes.
A biconnected component can also be a separation edge and its endpoints.
There are m-n+1 back edges in a graph.

BREADTH-FIRST SEARCH O(n+m) time in adjacency list
  used for: testing whether G is connected, computing a spanning forest, computing connected components, find minimum path between two nodes. computing cycle between two nodes or reporting there is no such cycle.
  mark start node level 0
  mark all incident nodes level 1
  in every iteration take all nodes of level 1 and mark all unmarked neighbours level 2
  and so on.
  Again it forms a spanning tree.

Use BFS when you need to find shortest path, otherwise use DFS (e.g., if you need to determine connectivity). NOTE this is for undirected graphs.

Directed Graphs.
  reachability is the directed equivalent of connectivity.
  u reaches v if G has a directed path from u to v
  STRONGLY CONNECTED: for every u,v u reaches v and v reaches u. Strongly connected implies cycles.
  ACYCLIC: digraph without directed cycles.
  TRANSITIVE CLOSURE: same vertices, but with an edge when the orig graph has a path.
  DFS in directed runs in O(n_s + m_s) time.
  Computing transitive closure, or determining the subgraph reacable from each vertex runs in O(n(n+m)) time, by repeatedly runnnig DFS for each vertex.
  Determining if two points are strongly connected can be done in O(m+n) by running DFS twice. The second time on the graph with all edges reversed.
  FloydWarshall algorithm uses dynamic programming to determine transitive closure of a digraph in O(n^3).
  You can perform DFS in-place (i.e., non-recursive) if you know which way to backtrack (by changing the edges to point back).

CHAPTER 7: WEIGHTED GRAPHS
==========================
The length or weight of a path is the sum of the weights of the edges.
DISTANCE: length of shortest path between two vertices.
Everything breaks when there are negative weight cycles.
Shortest path when all weights are 1 is BFS traversal.

Single-Source Shortest Paths
  Dijkstra's Algorithm (BFS on weighted graphs) is a greedy method. works when there are no negative weights. O (m log n) time or O(n^2 log n)
    works when weights are nonnegative.
    used for constructing shortest paths and computing minimum spanning trees.
    have a vector for distances (storing best path so far) from start to node
    initially d[start]=0 and d[everythign else]=100000
    put d in priority queue
    while items in priority queue
    pop top
    if d[start] is not key then stop
    otherwise mark it as seen
    go over all its neighbours that are still unseen (those that are in the queue)
    if there is a better way to the neighbour then update its d[x] (if d[u] + w(u,z) < d[z] then d[z]=d[u]+w(u,z) and add it to the queue.
    put all points in a priority queue, pop one and mark it as seen.
    Two implementations: one as a sequence O(n^2) and one as a heap O(m log n). prefer sequence when number of edges is large (m > n^2/log n).
  Bellman-Ford Shortest Paths Algorithm
    Works when there are negative edge weights. Works on directed graphs only.
    Perform nax n-1 times relaxation operation for every edges outgoing from every vertex.
    Running time O(n*m)
  Shortest Paths in Directed Acyclic Graphs
    A DAG has no directed cycles.
    A DAG allows for faster time on computing single-source shortest paths.
    Topological ordering of vertices can be done in O(n+m) time. So can DAG shortest paths.

CHAPTER 9: Text Processing
==========================

Strings
  proper substrings have size less than the original
  a prefix of P is a substring of P starting at 0
  a suffix of P is a substring of P ending at size-1
Pattern Matching (finding position of first substring)
  Brute force (quadratic)
  Boyer-Moore (O(nm) same as brute force)
    start backwards
    move past if none match
  Knuth-Morris-Pratt O(n+m)
    failure function says where to continue if you matched a previous part of p.
Trie space O(n) == radix tree
  tree-based data structure that allows for fast searching in a collection of strings.
  algorithm that preprocesses the text. Useful when a series of queries is performed on a fixed text.
  supports pattern matching adn prefix matching
  autocomplete tree
  each internal node has between 1 and d children, where d is the size of the alphabet
    - each node except root is labeled with a character
    - the ordering of the children of an internal node is determined by the canonical ordering of the alphabet
    - path from root to every external node forms a string
  either add an extra char to the end of each string or don't allow strings to have other strings as prefixes
  height of trie is equal to length of longest string.
  number of nodes in T is O(n), with n total length of strings
Compressed Trie
  advantage: number of nodes proportional to number fo strings, not their total length
  compressed trie only useful as an auxiliary index structure over a collection of strings already stored in a primary structure. does not store all characters of the strings, only indices to arrays.
  Space is O(s) s is nr of strings.
Suffix Tries/suffix tree/position tree
  Uses O(n) space while storing all suffixes explicitly would take O(n) space
  Can be constructed in O(n) (difficult algo)
  Pattern matching in O(dm) time, m length of pattern, wtih suffix trie using O(n) space that can be constructed in O(dn) time.

NP
  nondeterministically solvable in polynomial time. If you know what decisions to choose, you will find an answer.
  NP includes P
  alternate definition:
    - nondeterminisitically accepted in polynomial time
    - deterministically verified in polynomial time
  NP examples:
    - Hamiltonian-Cycle, simple cycle, visits each vertex exactly once and then returns to its starting vertex. whether it exists
    - Circuit-Sat: booleancircuit: is there a configuration of input vals to make the output 1
    - Vertex-Cover: whether each edge can be connected with a certain number of vertices from a graph
  NP-Complete: problem in NP but not in P.
  NP-Hard: every NP problem reduces to it (at least as hard as NP)
    NP-Hard + problem in NP implies NP-complete
    if every other problem in NP can be reduced in polynomial time to it
  NP-Complete examples:
    CNF-SAT (satisfiability with expressions) conjunctive normal form
    3 SAT every (a v b) & (a v b)
    2 SAT IS POLYNOMIAL
    Clique and Set-Cover: selecting a subset and optimizing size of subset while still satisfying some constraint. Clique is subset that is interconnected (e.g., max clique problem). Set-cover is finding k subsets of n sets that have same union as the n sets
    subset-sum and knapsack: is there a subset of integers that sums to k. knapsack: size and worth, is there a subset such that size <= s and worth >= w
      note: if you only had the size, then you could just use a greedy strategy
    Hamiltonian-Cycle and TSP: TSP = traveling salesperson problem. Visit all vertices in G at least once with total cost at most k.
  Dealing with NP efficiently:
    approximation algorithms
    exponential algs:
      backtracking: include it or not. stop if hopeless
      branch-and-bound: BFS: best-first search strategy: define lower bounds
  
  If you can't verify it in polynomial time, it's intractable, and not part of NP.

Clique = graph all interconnected

A*:  Dijkstra with a heuristic
BFS: Best first search: search graph by expanding most promising node

Livelock:
  keep doing the same thing over and over, but make no progress.
Deadlock:
  two or more competing actions are each waiting for each other to finish, and thus neither ever does.
Mutex:
 Like binary semaphore, only it can only be released by the thread that had acquired it. Only one task (thread or process) can acquire the mutex. And only the owner can release the lock. While a semaphore can be signalled from any other thread. So semaphores are more suitable for synchronization problems like producer-consumer. So binary semaphores are more like event objects than mutexes. The purpose is different: Mutex is a locking mechamism: used to synchronize access to a resource. Semaphore is a signaling mechanism (I am done you can carry on).
Semaphore:
  counting semaphores (allow arbitrary resource count), binary semaphores (0 or 1). E.g. there are 10 free rooms. When no rooms available, either wait in queue, or use round-robin scheduling and race back to the counter when someone releases a room. Semaphore tracks only how many are free, not which. V (signal, when going out) increments semaphore S, P (wait, when going in) decrements it. Increment, detriment and comparison operations need to be atomic. Producer Consumer
Monitor: when multithreading, and something needs to be synchronized
 intended to be used safely by more than one thread. its methods are executed with mutual exclusion. At any point in time, at most one thread may be executing any of its methods. Can be implemented using a semaphore that is initially unlocked, and locked at the start of each public method, and unlocked at each return from each public method.
Context switching:
  Storing and restoring the state (context) of a process so that execution can be resumed from the same point at a later time. This enables multiple processes to share a single CPU and is essential in a multitasking operating system. A context switch can mean a register context switch, a task context switch, a stack frame switch, a thread context switch, or a process context switch.
What resources a process needs:
  image of executable machine code
  memory (heap for variables, call stack for subroutines, input/output, executable code)
  descriptors (handles/file descriptors)
  security attributes (owner)
  processor state
What resources a thread needs: a stack, copy of registers including the program counter, and thread-local storage (if any). Threading sometimes occurs in user space, not in kernel space.
  processes are independent, threads exist as subsets of a process
  processes carry more state information. threads share the process state, memory and other resources
  processes have separate address spaces, threads share address space
  processes interact only through system-provided interprocess communication mechanisms
  context-switching between threads is faster than between processes
User space and kernel space
  Kernel space is strictly reserved for running privileged kernel, kernel extensions, and most device drivers. In contrast, user space is the memory area where all user mode applications and some drivers execute.
Scheduling:
  Goal: minimize resource starvation and ensure fairness.
  Preemptive scheduling: switch out processes that are still runnable. Otherwise only processes get switched out that make themselves unrunnable. 
  Cooperative: process determines when it gives up control (used in fibers)
  Three types: Long-term (which processes to run), medium-term (paging/swapping, i.e., priority of processes), short-term (which process to execute after a signal/interrupt/system call)
  Dispatcher handles the swithces, loads the data, sets the program counter, and so on.
  Types: round-robin: time slices, handling all processes in order, with no priority. No starvation. Fair queueing (max-min fairness, maximize the minimum data rate that any of the active data flows experience). (if packets are small, send more). Fifo

Trees
  binary trees
  n-ary trees
  trie-trees
  balanced binary tree
    red-black tree
    splay tree
    avl tree
    KNOW HOW TO IMPLEMENT
  BFS/DFS
  inorder, postorder, preorder
Hashtables:
  implement one using only arrays
Graphs:
  objects and pointers
  matrix
  adjacency list
  familiarize with each representation and its pros and cons
  You should know the basic graph traversal algorithms: breadth-first search and depth-first search. You should know their computational complexity, their tradeoffs, and how to implement them in real code.
  Dijkstra and A* are a plus

A*
  The time complexity of A* depends on the heuristic. In the worst case, the number of nodes expanded is exponential in the length of the solution (the shortest path), but it is polynomial when the search space is a tree, there is a single goal state, and the heuristic function h meets the following condition:

DP:
  make sure you go over all items, add an extra row for results or initialization if needed
  make sure you construct a solution that is suboptimal (optimal substructure & overlapping subproblems)
  always check limits, never assume anything, handle margin cases, and exceptions to the rule
  only rotate if advantage. no advantage if you have to clear (unless you are actively using the thing from 2 rounds ago)

  
http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=bitManipulation

gcc compiler options: http://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html#Option-Summary
currently using: -Wall -Wextra -Werror -O2 -Wno-reorder -Wno-sign-compare

C++:
You can't just .clear() a (string)stream. You have to do: r.str(""); r.clear();
When cin >> var fails, it doesn't actually assign anything to the variables. So if you're using the same variables in a loop, then you need to explicitly initialize them with a value (even if they're just ints or doubles) before the cin statements to see if that statement changed their value. If you don't initialize them, C++ initializes them to a random value which is probably the value that they had in the previous iteration of the loop.
To write LF to a file in windows instead of crlf (or, in fact, on any platform): ofstream f(filename.c_str(), std::ios_base::binary | std::ios_base::out); You don't need to do that for reading a file separated by only LFs.
The keywords fixed, setw, scientific, setfill, and setprecision all work only for the next number. The number you output right after it isn't modified.
When fixed or scientific is specified, setprecision determines the number of digits after the period, padding with zeros if needed. If neither fixed nor scientific is specified, setprecision sets the max number of meaningful digits (counting both those in front and behind the period) to be printed, but without padding if the value is shorter.
The modifier setw simply adds padding in front of shorter fields, and with setfill you can set a character that it should use for the padding.
count the number of occurrences of a character in a string: count(s.begin(),s.end(),'A')
-- 31-01-2015:
When you have two vectors, a.swap(b) or swap(a,b) (which are equally fast), are slightly faster than a = b (by about 10%).
If you call something with Something* = new ... you need to explicitly delete that object at the end of the scope or use unique_ptr (it is not done automatically for you!).
size_t is an alias for unsigned int
You can't initialize variables in a switch statement (because they will exist for the entire scope of switch) unless you use braces around the cases.
-- 02-05-2014:
to initialize a vector from an array of strings:
string a[] = {"hi", "this", "is", "something"};
vector<string> av(a,a+sizeof(a)/sizeof(string));
1e6 = 1 with 6 zeros behind it. = 10^6 = 1*10^6.
default value in a map is 0 for an int or double so you can just increase it even if it is not in there.
long double exists and is 12 bit compared to regular doubles which are 8 bit. Actually don't use long doubles since they appear to overflow to negative values for values > LONG_LONG_MAX. NEVER USE LONG DOUBLES.
when you want to know the number of unique permutations of a string that possibly contains multiple characters that are the same, you can use next_permutation(s.begin(),s.end()); i.e., directly on the string, after sorting the string (sort(s.begin(),s.end()).
next_permutation returns DISTINCT permutations only! so if some elements are the same, then you don't always iterate over n! permutations in the array.
accumulate(a.begin(),a.begin()+n,0) includes all items starting at index 0 that have index < n. or: the first n items.
How does it work when you do a*a*a%b*a, can you get overflows <-- no: because it is evaluated from left to right
minimum of something: *min_element(a.begin(),a.end());
custom sort without defining another class:  bool operator() (int i, int j) { return price[i] < price[j]; } and then just call sort(path.begin(),path.end(),*this);
if you're just doing + or - and the terms themselves do not reach LL values, then they themselves don't need to be LLs. Actually, they do (at least the most left of them).
vector<string> sort sorts alphabetically (i.e., the positions past the end of a string can be seen as a character < any other character). or: they are left aligned
You can't use memset with values other than 0 and -1 because it sets a the value for every byte rather than for every int. So if you memset() something to 1, you actually get an integer (which is 4 bytes) which looks like 00000001 00000001 00000001 00000001. So only values that are 4x repeated sequences of the same 8-bit pattern can be memset.
There is a difference between a char and an unsigned char (and same with int and unsigned int). Note that both the signed and unsigned variant have the same size. A char is 1 byte or 8 bits. max char is 2^7-1 = 127. Negative chars are allowed. So you can only flip and toggle 7 bits in a normal char (highest index that you can set to 1 is 6, but 0 counts as well). An unsigned char is also 1 byte or 8 bits, but doesn't allow negative values. So its max is 2^8-1 = 255. The highest power of 2 that can have a 1 is 7, but 0 counts, so you can still set 8 bits. Likewise, in a 32 bit signed integer, the highest value is 2^31-1, and the highest index you can set 1 is 30 because 0 counts too. So you can actually toggle 31 bits (and 32 in an unsigned integer).
multiset.lower_bound returns an iterator to the first value >= the given value. upper_bound returns an iterator to first value > the given value.
You use a multiset when you have sorted items that you want to erase some of (and maybe those are in the middle). If you want to sort them the other way around, simply insert the negative weight.
s.erase(5), where s is a multiset, erases ALL elements with that value. If you want to erase just one, do: s.erase(s.find(5));
To make something from ints a valid long long, each term that is separated by a + or - must have (LL). Because that's how it processes it. * and / take precendence, so those terms are calculated first, then when it sees that it should be an (LL), it's too late. Each term is calculated on its own before added, make sure at least one of those is a LL.
When you add multiple terms and their result can overflow, just the most left one needs to have (LL) in front of it (because it evaluates from left to right). If the individual terms can overflow (because they are a*a or something), something in that term needs to have (LL). This is because the terms themselves (if they are * or /) are evaluated before the addition.
So you are safe as long as: 1) if the result of the  - or + separated terms might overflow, the most left one has (LL). Each term that consists of * / does not overflow or contains at least one term with (LL).
NOTE: r+= when r is LL does not make the right term automatically LL.
Watch with negative numbers and .size().. you ALWAYS have to explicitly put (int) before it
Double is 8 bytes, same size as long long
You can initialize ints from hex notation with int a = 0x2E; for example, or for octal: 0x03F;
you can compare vector<int>'s directly: vector<int> a, vector<int> b, if (a < b) (probably only if they have the same size). If they don't have the same size, only the number of elements in the smallest thing are compared. If they are all equal, the one with more elements is seen as larger.
For any int or unsigned i, i ^ 1 is i+1 if i is even and i-1 if i is odd. You can use it to find the other side of an edge if you store undirectional edges after each other in an array.
If you have vector<string> a you can do if (a[0] == "sdfsdf") as well as if (a[0][0] == 's').
Vector swap is much more efficient than reassigning
A vector of, e.g., long longs initializes the values to 0 if you specify a size.
Remove all occurrences of a character from a string (works just like unique): b.resize(remove(b.begin(),b.end(),'z')-b.begin());
Remove all occurrences of a substring from a string: for (int i = s.find(p); i != string::npos; i = s.find(p)) s.erase(i, p.size());
You need to call sort() before using unique(), but you don't need to call sort() before using remove().
state ^= (1<<0); is equivalent to state ^= 1;
You have to put parenthesis before the not: if (!(bla&(1<<k))).
String concatentation: string s = accumulate(vs.begin(), vs.end(), string(""));
UNIQUE:  sort(events.begin(),events.end()); a.resize(unique(a.begin(),a.end()) - a.begin()); The sort is always needed (unless it's already sorte).
GCC extension. x >?= y is equivalent to: x = max(x, y); Also, x<?= y is the same as  x = min(x,y);
INT_MIN is actually -2147483648 while INT_MAX is 2147483647
c++ uses two's complement notation for negative integers: flip all bits then add 1 to the value. In two's complement notation, -2147483648 can be expressed (as 1 with 31 zeros). SO THE CLIMITS PAGE IS WRONG
When you do addition in C++, you can still go out of bounds when you add two ints together even if both are % some mod.
So one of them should be a long long always so that the addition is done in long long.
Replace substring (keep replacing): !! GOES INTO INFINITE LOOP if old string is a substring of new string
  void replace_substring(string& s, const string& olds, const string& news) {
    size_t pos = s.find(olds);
    while (pos != string::npos) {
      s = s.substr(0,pos) + news + s.substr(pos + olds.size());
      pos = s.find(olds);
    }
  }
Replace substring (ONCE): !! works also if old string is a substring of new string
  void replace_substring(string& s, const string& olds, const string& news) {
    size_t pos = s.find(olds);
    while (pos != string::npos) {
      s = s.substr(0,pos) + news + s.substr(pos + olds.size());
      pos = s.find(olds, pos + news.size());
    }
  }

--
You can't clear a stack<>. You have to empty it with pops.
% it has the precedence of the / operator which is same as *. so when read from left to right when equal.
filling a multidimensional array: (however it should also be possible with memset(mem,-1,sizeof(mem)), try it)
long long memo[FIRST][LAST][N][N][N];
ONLY USE MEMSET WITH VALUES 0 OR -1, for any other values use     fill(&dp[0][0][0],&dp[52][0][0],INF);
fill(&memo[0][0][0][0][0], &memo[FIRST][0][0][0][0], -1); // from <algorithm>. This is the end because the first index only goes up to [FIRST-1]. 
Element at the top of a priority_queue is the LARGEST element in the queue, not the smallest. So there is a difference with the theoretical heap order property. Think: top has MOST priority.
deleting and iterating over items from a set:
  for (set<int>::iterator i=a.begin();i!=a.end();) {
    cout << (*i) << endl;
    if (*i == 5) { i++; continue; }
    a.erase(i++);
  }
when reversing through the set:
  for (set<int>::reverse_iterator i=a.rbegin();i!=a.rend();) {
    cout << (*i) << endl;
    if (*i == 5) { i++; continue; }
    a.erase(--i.base());
  }
Something a = Else(); will treat object as something (copy constructor) Something* a = new Else(); will call else methods on it.
always do bitshifts in parentheses it has lower precedence than ==
uses two's complement notation for binary integers
if you define a function to print that is not the operator<< then don't use out << that_function(out,...) because it will print the outstream
int main (int argc, char *argv[]) 
back() is the last element of a list (you can't use the [] operator)
functor: call a variable like a function by defining the operator(): int operator()(int y) { return x + y; }
this->paramA = paramA in structs or classes to set local props; (this is a pointer)
digits come before characters, '0' comes before '9'
for comparison: bool operator<(const Player& p) const { return name < p.name; }
can't pass int array[] as a parameter without length (can't use sizeof(a)/sizeof(int) to determine it
int input[] works in C++, but int[] input does not
#include <cstddef> to include NULL
#include <cmath> for abs on doubles
#include <cstdlib> for rand() (number between 0 (inclusive) and RAND_MAX)
#include <algorithm> to sort a vector: sort(mgs.begin(),mgs.end());, also for max
if you put a name behind a class or struct, it creates an object of that class
new always returns a pointer
struct is like class except member fields are public by default instead of private
get single characters with a.get() while a.good()
C++ is always by val, Java/Ruby is always by var
int myarray [] = { 501,502,503 };
always pivot = (l+r)/2;
check for even/uneven is %2
template <class T, typename B>  <-- class and typename mean the same here
area of triangle is 0.5 times sqrt() of squared crossproduct of side vectors
you have to initialize references to actual objects always, but pointers not per se (pointers don't initialize to NULL btw, you have to do that manually)
int foo = 1000; int* b = &foo; (*b) to dereference it
>> string for sstream is spacedelimited, use string getline(ss,a) for whole line (use get() first if there is a space to be read)
example: b.get(); getline(b,c); // where c is a string
max of a vector:  *max_element(tmax.begin(),tmax.end());
erase char candidate from string newcandidate: newcandidate.erase(remove(newcandidate.begin(), newcandidate.end(), candidate), newcandidate.end());
intersecting rectangles is just the max of the mins and the minof the maxes
c++ switch only works on ints, not on chars or anything else (works in Java on Strings though)
setters and getters: V& operator[](const K& key); V operator[](K key) const;
clear means remove everything, erase means remove certain stuff only
initialize a vector of empty strings: vector<string>r(2*snowflake.size(),string(2*snowflake.size(),' '));
when you have lower triangular and shift the indices, you fill it out
when checking ortogonal/diagonal neighbours, if one of them is zero, you have orto otherwise diago
a "friend ostream& operator<< (ostream& os, Datum& dt )" does not define an ostream operator for the pointer object! use cout << *pointer.
static: When modifying a variable or function at file scope, the static keyword specifies that the variable or function has internal linkage (its name is not visible from outside the file in which it is declared).
# in define is literal value to string?
const behind params means the function does not modify the object for which it is called
const before data declaration, means that data is not modifiable
typedef struct in C meant that you could declare objects of that class
to save space: typedef std::vector<T> keytype;	typedef typename std::vector<T>::const_iterator const_iterator;
throw "blabla"; try { base[section].setdefault(line.substr(0,pos),line.substr(pos+1)); } catch(...) { }
squared array cannot have size more than 10000
A friend function is a function that is not a member of a class but has access to the class's private and protected members (of objects you pass as references)
inheritance: template<class T> class AVLTree : public BinSearchTree<T> { };
friend class Bla <-- by doing this you say that that other class can execute private and protected methods/objects
union datatype (declared same as struct): if value can be one of different types.
enum: different types enum class Suit { Diamonds, Hearts, Clubs, Spades }; use class to refer to obj as Suit::Diamonds... just assigning some constant names for int values. <--- enum class is in c++11
free when you used malloc, delete when you used new
you can only delete a pointer.
cannot use non-static member attributes as default arguments
You don't need to prefix superclass stuff with SuperClass:: ... if you didn't overwrite the function
You NEED to initialize pointers for new objects to NULL in the constructor. They are not set to NULL by default.
If you provide the body of a function after the class definition, that function still needs to be declared in the class. You cannot add functions to a class later (this isn't ruby).
queue uses front, priority_queue uses top
assignment with references:
a = b; // when a a reference and b an object, the object at address of a now has value of b
       // when a a reference and b is a reference, a now points to the same object as b
       // when a an object: constructs a copy of object b.
       // conclusion: if it's an object, copy, if it's a reference, point to same. Logical
NOTE: with references, you have to make a copy. you can't get out of it
in a copy swap, NEVER use the & thing.
If you do a reverse index into an array, like: g[g.size()-1-j] then the only requirement is that j>0
Not just pointers, but also regular ints are not set to 0 in objects by default. You really need to initialize everything. Actually, not everything, it's just that ints don't have a default constructor. But objects do. So you don't have to initialize objects. Just the default types and pointers (the objects that don't have default constructors).
If you do not declare a copy constructor, the compiler gives you one implicitly. You only need to declare your own if you are having raw pointers and you want to deep copy (i.e., copy the object that the pointers point to)
Always make references const if possible: There is a small clause in the C++ standard that says that non-const references cannot bind to temporary objects. Pass by non-const reference ONLY if the function will modify the parameter and it is the intent to change the caller's copy of the data, otherwise pass by const reference.
Declare an assignment operator if you're going to put your own class/struct that contains references to objects in a vector or other STL container. It should look like this:
  Edge& operator=(const Edge& e) {
    if (&e != this) {
      orig=e.orig;
      dest=e.dest;
      directed=e.directed;
      idx=e.idx;
      weight=e.weight;
    }
    return *this;
  }
Exception Safe: means that state remains valid if an exception is thrown at any point. An exception safe assignment operator does copy then swap.
Implicit member functions in C++ struct or class: default constructor (only if another constructor is not explicitly defined) and copy constructor, a destructor and a copy assignment operator. The copy constructor and the copy assignment operator perform a bit-wise (or shallow) copy, i.e. copying the variables bitwise. That means if you have a class that contains pointers to some objects, they just copy the value of the pointers and not the objects they point to. 

Find first or last set bit in a number:
  The 386 introduced CPU instructions for bit scanning: BSF (bit scan forward) and BSR (bit scan reverse). GCC exposes these instructions through the built-in functions __builtin_ctz (count trailing zeros) and __builtin_clz (count leading zeros).

__builtin_popcount
  how many bits are set.

To check if a number has 2 adjacent 1 bits:
  (i & (i << 1))

(-x ^ y) + x   ====> x ? -y : y  where x is 0 or 1

Setting a bit
Use the bitwise OR operator (|) to set a bit.
number |= 1 << x;
That will set bit x.
Clearing a bit
Use the bitwise AND operator (&) to clear a bit.
number &= ~(1 << x);  <-- note there is no point doing 0 << x EVER
That will clear bit x. You must invert the bit string with the bitwise NOT operator (~), then AND it.
Toggling a bit
The XOR operator (^) can be used to toggle a bit.
number ^= 1 << x;
That will toggle bit x.
Checking a bit
You didn't ask for this but I might as well add it.
To check a bit, AND it with the bit you want to check:
bit = number & (1 << x);
All subsets of 0 to 3 (inclusive) items with bitshifts:
int main() {
  int p,q;
  for (int t=0;t<16;t++) {  // 16 is 2^4
    p = 0; q = 0;
    cout << "reset" << endl;
    for (int i=0;i<4;i++)
      if (t & (1 << i)) { cout << "i: " << i << endl; }
  }
}

C++11
  GCD: while (b != 0) { tie(a,b) = make_tuple(b, a % b); } #include <tuple>
  auto
    Tell the compiler to infer a type. auto a = 44LL;. Primary use:less code (unless the type is an int). Use it for iterators. A function cannot return an "auto" type, but it can be auto, in which case it will determine the type (but it is still fixed), with decltype like this: auto sum(int a,int b) -> decltype(a+b) { } A function parameter cannot be declared auto. In other words: the reason you can't say auto a = ...; return a; is because it always needs to be the same type.
  nullptr
    Use instead of NULL which is 0. So we don't have implicit conversion to integers. Can be assigned to pointers of any type (e.g., int* a = nullptr) but cannot be assigned to regular values (int a = nullptr //gives an error). 0 is still a valid null pointer value for backwards compatibility.
  range-based for-loops
    Use for anything for which non-member functions begin() and end() are overloaded. Square an array in c++11: int arr[] = {1,2,3,4,5}; for(int& e : arr) { e = e*e; }
  override and final
    Two new keywords. Use override to indicate that a method is supposed to be an override of a virtual method in a base class, and use final to indicate that a derived class shall not override a virtual method. Put it after the other function arguments. Something can also be "override final", meaning it cannot be overriden by a derived class.
  strongly-typed enums
    traditionally, enums exported their enumerators in the surrounding scope, they are implicitly converted to integral tyeps and cannot have a user-specified underlying type. enum class Options {None, One, All}; Options o = Options::All;
  smart pointers (auto_ptr is now obsolete)
    reference counting/auto releasing of owned memory.
    you must include <memory> to do this stuff
      unique_ptr
        when ownership of a memory resource does not have to be shared (doesn't have a copy constructor). But it can be transferred to another unique_ptr (move constructor exists). For example you'd use a unique_ptr when you want an object to be destroyed when a parent object is destroyed. When you want the child object to possibly outlive the parent object, you'd use a shared_ptr. You only use a weak_ptr when there is already a shared_ptr going the other way. std::unique_ptr<int> p1(new int(42)); std::unique_ptr<int> p2 = std::move(p1); // p1 will be set to nullptr
      shared_ptr
        should be used when ownership of a memory resource should be shared. You can call auto p3 = std::make_shared<int>(42); // to create a shared pointer.
      weak_ptr
        Holds a reference to an object managed by a shared_ptr but does not contribute to the reference count. used to break dependency cycles (tree with children and parent nodes).
        auto p = std::make_shared<int>(42); std::weak_ptr<int> wp = p;
        weak_ptr must call lock() to access the object. lock() lasts the entire scope (no need to unlock).
   lambdas
     anonymous functions
     capture clause
       [=] by value
       [a] by value (only variable a)
       [&] by reference
       [&total] by reference (only variable b)
       []  compiler error if you try to use external variables (unless their storage is static)
       this is about variables not given as arguments of the lambda expression. i.e., those that are taken from the surrounding scope (at the time of declaring the lambda function, not at the time of calling it). But if you use [&], you can modify the values later and then when you call the lambda function it will use the updatedvalues.
       you don't have to declare when you use or modify variables with static storage. you can only capture variables with automatic storage. static in this case means file scope as well. and those are accessed by reference by default
     parameter list ()
       cannot have default arguments
       cannot have variable length
       cannot have unnamed parameters
       can be left out if you do not provide mutable/throw()/->
       can take another lambda expression as an argument
     mutable
       says that the function can modify external variables
       otherwise the compiler gives an error if you try to modify variables that are not given as arguments, even when you declare them by value
     exception specification throw()
       you can use throw() to indicate that the expression does not throw any exceptions.
       you get a compiler error if the lambda body throws an exception
     return type ->
       you can omit it if there is less than 2 return statements in your code (will be inferred by compiler)
       can return another lambda expression.
     lamba body { };
       can access class variables if declared within a class, and can always access variables with static storage.
       recursive lambda's work, but not with auto. this works:
       std::function<int(int)> lfib = [&lfib](int n) {return n < 2 ? 1 : lfib(n-1) + lfib(n-2);};
     can be assigned to function variables (#include <functional>) function<int (int, int)> f2 = [] (int x, int y) { return x + y; };
     other things that accept a lambda expression as argument: find_if, generate
  non-member begin() and end()
    template <typename T, size_t N>
	void foo(T(&arr)[N]) // <- weird
	{
	   bar(std::begin(arr), std::end(arr));
    }
  static_assert and type traits
    static_assert performs an assertion check at compile-time. If the assertion is true, nothing happens. If the assertion is false, the compiler displays the specified error message. Can only be done with static things
    type traits
      series of classes that povide information about types at compile time.
      #include <type_traits>
      	helper classes: for creating compile-time constants
      	type traits classes: to get type information at compile time
      	type transformation classes: for getting new types by applying transformation on existing types.
      static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
  move semantics
    &&rvalue references. rvalues typically don't have a name and a temporary objects.
	// move constructor
	Buffer(Buffer&& temp):
	   _name(std::move(temp._name)),
	   _size(temp._size),
	   _buffer(std::move(temp._buffer))
	{
	   temp._buffer = nullptr;
	   temp._size = 0;
	}
	// move assignment operator
	 Buffer& operator=(Buffer&& temp)
	 {
		assert(this != &temp); // assert if this is not a temporary

		_buffer = nullptr;
		_size = temp._size;
		_buffer = std::move(temp._buffer);

		_name = std::move(temp._name);

		temp._buffer = nullptr;
		temp._size = 0;

		return *this;
	 }

STRUCT SIZE:
  is always the next power of 2 that fits (only if there are multiple different types)
  bool       = 1 byte
  char       = 1 byte
  int        = 4 byte = 32 bit value   (max val = 2^31 -1 =             2.147.483.647 = 2.15 billion)
  char*      = 4 byte = 32 bit address (max val = 2^63 -1 = 9.223.372.036.854.775.807 = 9e18 = 9*10^18 = 9 with 18 zeros)
  double     = 8 byte = 64 bits  (doubles don't actually have a max, they just lose precision)
  long long  = 8 byte = 64 bits
  long long* = 4 byte = 32 bits architecture


MULTIBYTE CHARACTERS
  Should work just fine, if it doesn't, encode the file in UTF-8. and either treat stuff as wstrings or don't.
  wstring a = L"blaaat";
  string b = string(a.begin(),a.end());


KMP Knuth Morris Pratt substring pattern matching O(n+k)
  The KMP algorithm returns the first occurrence of a string in another string.
  The KMP function indicates when a string started repeating itself (if the last value is is high it means all values are repetitions). Return s.size()-kmpf[kmpf.back()] to get the length of the shortest pattern such that the string can be seen as a a repetition of that patterns. == also the number of rotations of the given string.
vector<int> kmpf(string p) {
  vector<int> r(p.size(),0);
  int i = 1;
  int j = 0;
  while (i < p.size()) {
    if (p[i] == p[j]) {
      r[i++] = ++j;
    } else if (j > 0) {
      j = r[j-1];
    } else {
      r[i++] = 0;
    }
  }
  return r;
}
int kmp(string t,string p) {
  vector<int> r = kmpf(p);
  int i = 0;
  int j = 0;
  while (i < t.size()) {
    if (t[i] == p[j]) {
      if (j+1 == p.size()) return i-j;
      i++;
      j++;
    } else if (j > 0) {
      j = r[j-1];
    } else {
      i++;
    }
  }
  return -1;
}

MOST MATCHES, i.e., MOST OVERLAP IN SEQUENCE  === LONGEST COMMON SUBSEQUENCE
  int most_matches(vector<LL> A, vector<LL> B) {
    int dp[A.size()+1][B.size()+1];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=A.size();i++)
      for (int j=1;j<=B.size();j++) {
        if (A[i-1] == B[j-1])
          dp[i][j] = 1+dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    return dp[A.size()][B.size()];
  }

LONGEST SUBSTRING WITHOUT DUPLICATES:
  int maxLength(string letters) {
    int mx = 0;
    for (int i=0;i<letters.size();i++)
      for (int j=i;j<letters.size();j++) {
        bool ok = true;
        for (int k=i;k<j;k++)
          if (letters[k] == letters[j]) { ok = false; break; }
        if (!ok) break;
        mx = max(mx,j-i+1);
      }
    return mx;
  }

NTH SMALLEST (not quite a Fenwick/BIT data structure)
  using two multisets: use if the xth smallest element you have to retrieve doesn't vary by much, or otherwise use multiple of them.
  
  template <class T>
    class NthSmallest {
      multiset<T> left;
      multiset<T> right;
      int n;
     public:
      NthSmallest(int n) : n(n) {}
      void insert(T i) {
        if (left.size() < n) {
          left.insert(i);
          return;
        }
        left.insert(i);
        T elem = *left.rbegin();
        left.erase(left.find(elem));
        right.insert(elem);
      }
      T nth_smallest(int m) { // returns the element at array index m
        if (m == 0) return min_elem();
        while (left.size() > m) {
          T elem = *left.rbegin();
          left.erase(left.find(elem));
          right.insert(elem);
        }
        while (left.size() < m && right.size()) {
          T elem = *right.begin();
          right.erase(right.find(elem));
          left.insert(elem);
        }
        n = m;
        if (right.size()) return *right.begin();
        return *left.rbegin();
      }
      T min_elem() {
        if (left.size()) return *left.begin();
        return *right.begin();
      }
  };


INTERSECTION POINT OF TWO LINES
  pair<double,double> intersection(double x1s, double y1s, double x1e, double y1e, double x2s, double y2s, double x2e, double y2e) {
    double m = ((y1e-y1s)*x1s+(x1e-x1s)*y2s-(x1e-x1s)*y1s-(y1e-y1s)*x2s)/((y1e-y1s)*(x2e-x2s)-(x1e-x1s)*(y2e-y2s));
    return pair<double,double>(x2s+m*(x2e-x2s),y2s+m*(y2e-y2s));
  }

CROSS PRODUCT TO DETERMINE IF POINT LIES LEFT OF LINE (cross product is twice the area)
  bool left_of_line(const PII& p, const PII& from, const PII& to) {
    int d = (to.first-from.first)*(p.second -from.second) -
    (to.second-from.second)*(p.first - from.first);
    return d>=0;
  }

TRIANGLE AREA (points have to be given in counterclockwise order(?))
  double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
      x1 -= x3; y1 -= y3; x2 -= x3; y2 -= y3;
      return (x1 * y2 - x2 * y1) / 2;
  }

GAUSSIAN ELIMINATION (RANK OF A MATRIX)
  int rank(vector<vector<int> > a, vector<int> b, int p) {
    // p is the mod
    int n = a.size();    // n == number of variables (b also has size n) 
    int m = a[0].size(); // m == number of equations
    int r = 0;
    vector<bool> used(n,false);
    for (int i=0;i<m;i++) {
      int j = 0;
      while (j < n && (used[j] || a[j][i] == 0)) ++j;
      if (j == n) continue;
      used[j] = 1;
      ++r;
      for (int k=0;k<n;k++) {
        if (used[k]) continue;
        for (int l=0;l<p;l++)
          if ((l*a[j][i] + a[k][i])%p == 0) {
            for (int g=0;g<m;g++)
              a[k][g] = (a[k][g] + l*a[j][g])%p;
            b[k] = (b[k] + l*b[j])%p;
            break;
          }
      }
    }
    for (int i=0;i<n;i++)
      if (!used[i] && b[i]) return -1;
    return r;
  }

BINARY SEARCH LOWEST MATCH
 int find(vector <int> X, int elem) {
   // X is sorted in ascending order
   // return index of first occurrence or -1 if elem not found
   int l = 0, r = X.size()-1;
   while (l != r) {
	 int m = (l+r) >> 1;
	 if (X[m] >= elem) r = m;
	 else l = m+1;
   }
   if (X[l] != elem) return -1;
   return l;
 }
 while(hi - lo > 1) {
	int mid = (lo + hi) / 2;

	if(is_possible(mid, girls, enemies))
		hi = mid;
	else
		low = mid;
 }
 // TO GET THE BIGGEST ELEMENT, just swap the statements hi = mid and low = mid.
 return hi; // return the smallest possible F

ERATOSTHENES SIEVE : GETPRIMES GET PRIMES <= SQRT(N)
  vector<int> primes(int n) {
	vector<bool> prime(n+1,true);
	for (int i=2;i*i<=n;i++)
	  if (prime[i])
		for (int j=i*i;j<=n;j+=i)
		  prime[j] = false;
	vector<int> r;
	for (int i=2;i<prime.size();i++)
	  if (prime[i]) r.push_back(i);
	return r;
  }
   
GET PRIMES <= N
  vector<int> primes(int n) {
   	vector<int> prime;
   	for (int i=2;i<=n;i++) { // NOT i*i
   	  bool ok = true;
   	  for (int j=0;j<prime.size();j++)
   		if (i%prime[j] == 0) {
   		  ok = false;
   		  break;
   		}
   	  if (ok) prime.push_back(i);
   	}
   	return prime;
  }

LONGEST PATH IN A DIRECTED GRAPH // this caches the longest paths for each node (see how much it saves)
  int rec(int x) {
    int res = dp[x];
    if (res == -1) {
        res = 0;
        for (int i=0; i < degree[x]; i++) {
            res = std::max(res, rec(g[x][i]) );
        }
        if ( compressed[x] ) {
            res++;
        }
    }
    dp[x] = res;
    return res;
  }
  memset(dp, -1, sizeof(dp));
    int mx = 0;
    for (int i = 0; i < m; i++) {
      mx = max(mx, rec(i));
  }

DFS DISTANCE BITMASK OF EDGES ON PATH (WORKS ONLY IN A BIDIRECTIONAL TREE)
  long long dfsdist(int cur, int prev, int endn, long long ways) {
    if (cur == endn) return ways;
    long long r = 0;
    for (int i=0;i<roads.size();i++) {
      int from = i+1;
      int to = roads[i];
      if (from == cur) swap(from,to);
      if (to == cur && from != prev) {
        r |= dfsdist(from,cur,endn,ways|(1LL<<i));
      }
    }
    return r;
  }

POW PW function
  use it when working with powers of long longs and using doubles would cause a loss in precision
  LL pw(LL x, int p) {
    LL ret = 1;
    while (p) {
      if (p%2 == 1) ret *= x;
      x *= x;
      p /= 2;
    }
    return ret;
  }

DIJKSTRA
  priority_queue<PII> q;
  cost[i] = costings[i/m][i%m] == '1';
  q.push(PII(-1*cost[i],i));
  while (!q.empty()) {
    PII p = q.top();
    q.pop();
    int i = p.second/m;
    int j = p.second%m;
    if (cost[p.second] != -1*p.first) continue;
    int dx = 0, dy = 1;
    for (int l = 0;l<4;l++) {
      if (i+dx >= 0 && i+dx < n && j+dy >= 0 && j+dy < m) {
      int ni = (i+dx)*m+j+dy;
	  int tcost = costings[i+dx][j+dy] == '1';
	  if (cost[ni] == -1 || tcost+cost[p.second] < cost[ni]) {
	    cost[ni] = tcost+cost[p.second];
	    q.push(PII(-(tcost+cost[p.second],ni));
      }
      swap(dx,dy); dy *= -1;
    }
  }

MAXIMUM BIPARTITE MATCHING MBPM MAXFLOW
  bool bpm(int l,vector<int>& leftof,vector<bool>& seenl, vector<bool>& seenr) {
    if (seenl[l]) return false;
    seenl[l] = true;
    for (int r=0;r<nr;r++) {
      if (seenr[r] || !g[l][r]) continue;
      seenr[r] = true;
      if (leftof[r] == -1 || bpm(leftof[r],leftof,seenl,seenr)) {
        leftof[r] = l;
        return true;
      }
    }
    return false;
  }
  int calc() {
    vector<int> leftof(nr,-1);
    int r = 0;
    for (int l=0;l<nl;l++) {
      vector<bool> seenl(nl,0);
      vector<bool> seenr(nr,0);
      r+= bpm(l,leftof,seenl,seenr);
    }
    return r;
  }
  
FACTORIAL
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }

BICO FOR MULTIPLE NUMBERS 1-50
  const int kMod = 1e9+9;
  int comb[51][51];
  for (int i=0;i<=50;i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int j=1;j<i;j++)
      comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%kMod;
  }

FASTEST BICO FOR LARGE NUMBERS UP TO A MILLION (takes about 500ms to initialize)
const int kMod = 1e9+7;
const int kSize = 1000001;
int fact[kSize];
int inv[kSize];
long long pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % kMod;
    if (step & b) x = (long long)x * a % kMod;
    step >>= 1;
  }
  return x;
}
long long bico(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  int x = fact[n];
  int y = inv[k];
  int z = inv[n - k];
  return (long long)x * y % kMod * z % kMod;
}
fact[0] = 1;
    for (int i = 1; i < kSize; i++) fact[i] = (long long)fact[i - 1] * i % kMod;
    inv[0] = 1;
    for (int i = 1; i < kSize; i++) inv[i] = pw(fact[i], kMod - 2);


CORRECT BICO (BICO FOR LARGE NUMBERS WITH MOD (n can be as large as 1e9, runs linear in time k))
  const int kMod = 1e9+9;
  long long modPow(long long x, long long y) {
    long long r=1;
    long long a=x;
    while (y > 0) {
        if ( (y&1)==1 ) {
            r = (r * a)%kMod;
        }
        a = (a * a)%kMod;
        y /= 2;
    }
    return r;
  }
  long long modInverse(long long x) {
    return modPow(x, kMod-2);
  }
  long long bico(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k > n-k) k = n-k;
    long long r = 1;
    for (long long i=0;i<k;i++)
      r = ((n-i)%kMod*r%kMod*modInverse(i+1LL))%kMod;
    return r;
  }
  // this is the same as:
  LL bico(LL n, LL k) {
    if (k < 0 || k > n) return 0;
    if (k > n-k) k = n-k;
    LL numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++)
      numerator = (numerator * (n-i))%kMod;
    LL denominator = 1; // k!
    for (int i=1; i<=k; i++)
      denominator = (denominator * i) % kMod;
    return (numerator*modInverse(denominator)) % kMod;
  }

BITCOUNT
  int bitcount(int n) {
    int r = 0;
    for (int i = n;i;i&=i-1) ++r;
    return r;
  }

  int bitcount(long long t) {
    t = (t&0x5555555555555555LL) + ((t>>1)&0x5555555555555555LL);
    t = (t&0x3333333333333333LL) + ((t>>2)&0x3333333333333333LL);
    t = (t&0x0f0f0f0f0f0f0f0fLL) + ((t>>4)&0x0f0f0f0f0f0f0f0fLL);
    t = (t&0x00ff00ff00ff00ffLL) + ((t>>8)&0x00ff00ff00ff00ffLL);
    t = (t&0x0000ffff0000ffffLL) + ((t>>16)&0x0000ffff0000ffffLL);
    t = (t&0x00000000ffffffffLL) + ((t>>32)&0x00000000ffffffffLL);
    return t;
  }

ZERO BITS
  int zerobits(int n) {
    if (!n) return 0;
    int a = 1<<30;
    while (!(a&n)) a>>=1;
    return bitcount((a-1)&~(n));
  }

DFS number of distinct trees in a tree graph
  long long cnt;
  long long dfs(const vector<vector<int> >&g, int pos, int prev) {
    long long res = 1;
    for (int i=0;i<g[pos].size();i++) {
      if (g[pos][i] == prev) continue;
      res *= dfs(g,g[pos][i],pos) + 1;
    }
    cnt+=res;
    return res;
  }
  long long count(vector <int> a, vector <int> b) {
    int n = a.size()+1;
    cnt = 1;
    vector<vector<int> > g(n);
    for (int i=0;i<a.size();i++) {
      g[a[i]-1].push_back(b[i]-1);
      g[b[i]-1].push_back(a[i]-1);
    }
    dfs(g,0,-1);
    return cnt;
  }

DISJOINT SET FORESTS (assign to each node a number representing the connected component it belongs to)
int parent[27];
void reset(int n) {
  for (int i=0;i<=n;i++)
    parent[i]=i;
}
int find(int u) {
  if (u==parent[u])
    return u;
  else
    return parent[u]=find(parent[u]);
}
void merge(int a,int b) {
  int pa=find(a);
  int pb=find(b);
  if (pa != pb)
    parent[pa]=pb;
}

LINEAR TIME MAJORITY VOTING ALGORITHM
  // at the end, best is the best value
  // then do one more pass through the whole thing to see if it actually is a majority.
  void update(int& best, int& cnt, int val) {
	if (cnt == 0) {
	  best = val;
	  cnt = 1;
	} else {
	  if (best == val) cnt++;
	  else cnt--;
	}
  }

FLOYD-WARSHALL TRANSITIVE CLOSURE TAKING PATH LENGTH INTO ACCOUNT
  // i.e., can we get from A to B in x steps.
  fill(&gg[0][0][0],&gg[26][0][0],0.0);
	  for (int i=0;i<g.size();i++) {
		gg[0][i][i] = 1;
		for (int j=0;j<g.size();j++)
		  if (g[i][j])
			gg[1][i][j] = g[i][j];
	  }
	  for (int d=1;d<26;d++)
		for (int d2=0;d2<d;d2++)
		  for (int k=0;k<g.size();k++)
			for (int i=0;i<g.size();i++)
			  for (int j=0;j<g.size();j++)
				if (gg[d2][i][k] != 0 && gg[d-d2][k][j] != 0)
				  gg[d][i][j] = max(gg[d][i][j],gg[d2][i][k]*gg[d-d2][k][j]);


NUMBER OF MAXIMALLY CONNECTED SUBCOMPONENTS IN A GRAPH
  O(n^2): Use DFS

tourist way of doing unique sequences of cards of a type
  f[0] = 0;
  for (int i=1;i<=K;i++) {
    f[i] = 1;
    for (int j=0;j<n;j++) {
      for (int u=1;u<=c[j];u++) f[i] = (long long)f[i] * (i-u+1) % md;
      for (int u=1;u<=c[j];u++) f[i] = (long long)f[i] * inv[u] % md;
    }  // f is just the product of the bico's of all types: C(i,c[j]) for all j
    // So we count all ways to divide the points over the i segments in such a way
    // that we have at most one point per segment
    // But, this also includes cases where one of the segments was left empty (not chosen by any point)
    // If this is the case, then we would have found a valid segment at a lower i, and so we
    // subtract those options.
    // However, any such sequence could have "empty" barriers inserted at any position to make it
    // valid sequences that are currently counted. So we need to subtract not just the number of valid
    // sequences, but that times the number of ways that current sequences could be made from it
    // since the i-j empty barriers can be put anywhere in the string, even on the same position
    // we multiply ft with C[len+i-j][i-j].
    // Note that this is len and not len-1, since we can put an empty barrier at the start or at the end
    // Note that this is len+i-j, because they're independently calculated, and so it could be that
    // empty barriers are on top of each other.
    for (int j=1;j<i;j++) {
      int ft = f[j];
      ft = (long long)ft * C[len+i-j][i-j] % md;
      f[i] = (f[i] + md - ft) % md;
    }
  }
  return f[K];
  
lyrically's way of doing bico times factorial:
  dp[0][0] = 1;
  for (int i = 0;i<L;i++)
	for (int a = 0;a < W; a++)
	  if (dp[i][a])
		for (int j = i+1;j<=L;j++) {
		  // so from every pair of states we consider transferring character a
		  dp[j][a+1] += dp[i][a]*(W-a); 
		                                // NO!!!! You are saying: you're using character a from
		                                // index i to index j, and then you're choosing something else.
		}                               // And note of course that every such sequence is a different
		                                // one, since after it we immediately choose another character
		                                // and we never choose one that we already used.
  return dp[L][min(L,W)];




COMPETITIONS:
  If there is a calculation like x+y that you tend to think of as calculating a whole set of in a separate function and then comparing the set of results of two calls to that function, sometimes it is more efficient to write one function that performs the operation on two sets interweaving the calculations.
  You can invert a bitmask with the bitwise not operator (~). You often use this in combination with an and & on the maximum mask, so e.g.: ((1<<max_bits)-1)&(~mask) to get the inverted mask within the max_bits space.
  If your solution is too slow, see if you can precalculate repeated calculations that either do not make use of the state or that make use of the state but that calculating them once is better than doing it repeatedly in recursive function calls.
  Also see if you can simplify the state e.g. deriving from the bitmask when it is the last round and not adding that separately to the state.
  If you find that in your recursive function there's ever only one possible recursive call, you don't need a recursive function or memoization. You can just write a linear function that does the same logic.
  What you have to do in a recursive step is add one vertex to the graph (RandomGraph srm 620 1k). For the result to be the probability of a valid graph to happen, we have to sum over the possibilities of all possible valid graphs. That is why we sum over the recursive calls. Different ways to get to the same new state can be added separately as separate options.
  The different options in a branch don't have to add up to one. This is almost never the case. In this particular case, it is the case because many graphs are invalid but just a small percentage is valid.
  The probabilities for adding an edge to the graph being independent means that you can multiply them since they don't affect each other.
  In each possibility, we add a vertex to a graph with a certain number of edges. That means that the result will be summations of:
	(probability of adding exactly x edges (if p for one edge, then p^x)) *
	(how many distinct possibilities do we have for choosing x edges) *
	(probability of not adding any other edges == (1-p)^(# vertices it doesn't connect to))
  When you want all of them to hold:
	 p ^ (number of distinct ways to choose 1)
  When you want none of them to hold:
	 (1-p) ^ (number of distinct ways to choose 1)
  When you want only one of them to hold:
	 p * (number of distinct ways to choose that 1) * (1-p) ^ (number of things you don't want to hold)
  If a problem description goes like "what is the probability that the random graph generated contains at least one component with 4 or more vertices", calculate the inverse: a random graph without connected components of 4 or more vertices. Then the result is 1 - that probability.
  When you have to count the number of distinct strings and you know that n distinct characters are used in these strings, simply count the number of distinct patterns and multiply that by n!. A pattern is where you name each new variable e.g. x_i, starting from the left.
  If you want to determine whether a family tree works, i.e., it is only males and females coupled to each other, it means that it has to be a bipartite graph. Since in a valid graph, they all need to reduce to 2 colors, you can just use DFS to give every node the correct color immediately.
  When considering board states: always try to think of a board state as rectsum[i][j]: the number of items that appear in cells left above 0,0 to i,i include (i.e., convert the state to cumulative amounts). When all cumulative amounts for all cells are equal, the boards are equal too. You can calculate this state in constant time by doing: rectsum[i][j] = rectsum[i][j-1]+rectsum[i-1][j]-rectsum[i-1][j-1] (assuming proper checks).
  In recursive solutions where you supply a vector as part of the state (possibly by swapping two elements within the vector), see if you can't reuse the same vector, by swapping elements before the recursive call and then swapping them back after.
  When you have some sort of balance to keep between edges, iterate over the vertices: simply remove one edge, and then continue from the vertex it connects to to make it satisfy the property. increasing indices makes it so that it is a guarantee that anything below the current index is valid and after invalidating, becomes valid again.
  The maximum distance between two odd non-prime numbers is 8, and that only happens for 1 and 9, otherwise the maximum distance is 6. (Meaning that nonprimes are very common and you don't really have very long segments where all odd numbers are primes.)
  When combinations are counted as multiplications of 4 edge lengths, when you subtract something for being invalid, that also has to be a product of 4 edge lengths (TwoLLogo.cpp).
  If you have a problem where you need to identify the coins returned by a cash machine such that every coin needs to occur a different amount of times but where the machine will choose the least amount of coins to return and all coins divide each other, then you find a solution by sorting the limits (how many times the current coin can occur before it is equal to the next coin), and then iterating over them and assuring that every entry limits[i] is at least i+1 in size (ColorfulCoinsEasy.cpp: can also be solved by mincost/maxflow).
  When, at the end, you only need to know whether a value y in your state is a multiple of a constant x, then in your state only keep track of y%x, and at the end check if it is 0.
  With long distances dijkstra in a bidirectional graph, you can simplify the problem by realizing that T%(2*d) is a distance that we can keep adding 2*d to and then it will eventually reach T. Then just calculate all possible paths modulo 2d.
  If you want to know whether something is a possible output: simply run simulation over all possible inputs (which are elements in the set). Or: simply go through the array in order, and keep a set of points that cannot currently be in output. As long as the item is not in this set, it can be in the output and therefore its double can now also be in the output. Use this to erase the double value from that set.
  Sometimes if you can't store something in a state (because it would be a longlong number of combinations), you can use it as the result of the function call and store it like that instead.
  If you have a set of points in a plane, and a subset of those need to be in a square of minimal size, simply iterate over the set that has all possible combinations of x and y coordinates, and define that as (say) the left bottom of the set (don't think about orientation), and calculate for each point the minimum distances to include that point in the set, then if the set of points that lies to the top right of our point is >= the sought value K, then return the sorted distance of the Kth point as minimal required square distance.
  The expected number of steps to hit a goal node is "hitting time" on a random walk on a graph and defined as cnt*(goal-cnt).
  Determine the color of a square on a chessboard: (x+y)%2
  If you have a problem where N-2 points must lie strictly inside a square, sometimes it's easier to go over all possible sets of N-2 points, and calculate the area that is needed to surround those points, rather than to start doing math seeing how many points are on the boundary if you choose a minimum over all points.
  If you have a problem where you count the number of combinations, and the state doesn't change by adding a card, you should still keep counting the combinations. Also, you should keep counting while k is zero and only don't go into states where k would become less than zero.
  In rec functions, your single end point is idx == n. Don't stop for any other conditions (e.g., that a variable k in your state should be >= 0), instead: check those other conditions before the rec call in the function body. Otherwise you might lose out on combinations that don't change the state but should be counted double. (TaroCards.cpp)
  If you calculate values based on numbers that are supposed to be the GCD and LCM of those numbers, make sure that you check that they actually are the GCD and LCM of those numbers. (GCDLCMEasy.cpp)
  If you want to know if something is reachable by using all jumps (note that the sequence in which they're used doesn't matter), then if there is 1 jump, it has to be exactly the length of the distance, and otherwise, it is reachable if the distance is less than the total sum of jumplengths and the absolute difference between the longest jump and the distance is less than or equal to the sum of the rest of the jumps. (Jumping.cpp)
  How to know if something lies on a bulls eye pattern (Target.cpp): min(x,n-1-x,y,n-1-y)%2 == 0. That is, you calculate the minimum straight distance to any edge. This is either minimum distance to an edge or maximum distance to the center.
  If you have a problem where you need to find the maximum number of missions, and each mission gives you some fuel back, then you have to go over all 2^n combinations (using memoization/dp), and for each combination of cities, you want to find out whether that combination is possible, so you order it so that you process the one that gives the most fuel back first. Since it's only about whether or not that ENTIRE combination can be processed, nothing else in the ordering matters.
  ! You can save a dimension in your state space if you only use the previous result by using dp instead of recursion. If the DP can be progressed such that you can traverse it in some order and replace everything in-line, you don't even need [2] in the state space.

  -- 23-01-14
  When you have to calculate the submatrix rectangle of values that all have some value, create a matrix of the same size in which the values are the counts of how many subsequent values on or above that line have the same value. Do this for each of the values. (TheMatrix.cpp)
  Instead of iterating over all 100.000 possible values of v to pick for which size the variety pack should be, you can also note that the outcome will only be different at specifidc points of v, namely those that are the size of some objects in X, i.e., that empty out X. Otherwise you would need binary search. So then instead of over the possible values, the loop would be over the indices of X.
  When you want the longest substring where the left side is L and the right is R, start from both sides and in linear time try to keep advancing to the middle as long as both sides find a match before they find each other.
  You can use memoization to cache the longest path in a graph.
  On a dfs only go in a node if you haven't visited it before. Always check. Simply starting at a higher index doesn't guarantee you anything (the order can't be relied upon).
  Note that in your typical DFS you can start at node+1 (when you're looking for nodes that have -1 color) because all earlier ones have an assigned color.
  The minimum amount of boxes to open: either start with nothing and add the biggest lower boundary, or start with everything and remove the smallest upper boundary (because in worst case that's the only thing you remove). Update the value as long as you get an amount that is >= what you are looking for.
  If you know the naive solution to a problem but you don't know when and if you can stop searching for a solution, try to see if you can say something about the way that the size of the solutions diverges or converges.
  If you have a problem where you are walking a path and you want to know if it is bounded, note that when you have 4 directions to go to, each direction will have the same difference, so either something turns you by 90 degrees (which means that after 4 turns you'll have full circle), or it turns you by 180 degrees (again, after 4 turns you'll have 2 full circles), or by 270 degrees (which is actually just 90 degrees again, so after 4 turns you have full circle), or it doesn't turn you at all so after 4 turns you'll have full circle. In either way, just checking after 4 turns whether you are at your origin still is enough (because you will be facing the same position as originally).
  The problem that you have a number of legs and heads and you have to determine how many animals you had can be solved by math but sometimes also by simulation, where you just try the different ways in which a number x of heads 0 <= x <= n can be assigned to be cows. At the end always check whether one of your results is not negative.
  If you can't come up with a solution then it might be the case that there is some math involved. Simply write a naive solution that won't work for the full input domain, and see if you can derive any statistics from the answer ranges that are valid.
  If you have two dots on a line, there is exactly 50% chance that their line segments to dots on a parallel line will cross, for any two points. Because the crossing doesn't depend on the position of those points, it depends on the position of the points on the other side. If they're in the same sequence, they cross, otherwise they don't.
  If you can decide which selection of boxes to choose, and you want the minimum number of boxes such that you get X, then you have two selections: the boxes you don't open (which will logically have the lowest capacity), and the boxes you do open (with the highest capacity). Now since we can determine the boxes we do open, we also know the boxes that we don't open. We need to satisfy two conditions: the capacity of what you open should be >= X, and the capacity of what you don't open should be <= C-X. And the sum of those capacities is the total capacity (i.e., the sets complement each other). Then the answer is the smallest number of boxes for which this holds.
  Strongly connected component (find using Tarjan's algorithm in O^2 or Floyd-Warshall in O^3), is a part of the graph where every vertex is reachable from every other vertex. Reachable, not connected.
  The number of walks of a certain length L in a directed graph is unbounded only when there is a node that has outgoing edges to two distinct points, each of whom have a path back to the original node (these paths may intersect, doesn't matter). (BigO.cpp)
  The difference between walk and path is that walks can visit the same vertex multiple times, in a DAG, this is not possible.
  The expected value of a random variable that depends on some sum: linearity of expectation.
  If you have a DP problem, try to reduce it so that you always move in one direction, even if it might appear that you move in two opposing directions (e.g., if the thing is circular).
  Check memory limits of programs. Sometimes you explicitly have more than 64MB.
  Maximum number of pairs of distinct elements problem: the number of distinct pairs is fully determined by the element that has the most occurrences. If this number of occurrences is > n/2 (i.e., if it has a majority), we can calculate how many times it pairs with itself and subtract that of n/2 (which would normally be the answer if there is no item that has a majority).
  When you are given a big stream of numbers, you can determine whether one of them has a majority by applying a linear time constant space majority voting algorithm to determine the one that has the majority (i.e., without keeping all of them in memory). You need another pass to determine whether the selected element actually has a majority or whether there is a draw. NOTE: When the given sequence does not have a majority (i.e., an element that occurs in more than n/2 cases), it does not necessarily output the item with the highest number of occurrences. It only gives sensible output when there is an element that has a majority.
  Always see if you can calculate the state. Knowing how many possibilities there are allows you to reduce the state. If something multiplies its neighbours, then the order in which the events happened doesn't matter, and also, you can recalculate the exact values knowing just which ones were turned to zero.
  When you have a state where an element can either be emptied, causing the surrounding elements to be doubled, or not, the actual state size is 1 bit per var. Because you can calculate how many times the others were doubled just by knowing which ones were emptied. If you use a map, you don't need to account for this specifically, your state will already reflect this.
  You can combine passing a vector by reference as state in a rec argument with memoization (i.e., you look up the state in a map as a pair of the vector and something else) as long as the number of states is relatively small, simply because all operations that interact with a map make a copy of the reference vector, so you can just store it and retrieve it without having to do anything special.
  There is a huge difference in making a new copy of a vector or modifying the existing one, even if the vector has a maximum of 10 characters and you never go more than 10 in depth at the same time.
  If you are playing a two-player adversarial game, and each player wants to optimize their own score, it can be that you want to maximize some criterion that is defined as the difference in scores (my score - their score). Then you can use a single recursive function where you say: return (my maximum earnings in this turn) - their maximum difference for the remaining turns.
  maximum spanning tree algorithm is the same as the minimum spanning tree algorithm.
  Minimum spanning tree algorithm (Prim's algorithm), works greedy: start with a random vertex. Then repeat: add the edge connecting a vertex of the set to a vertex not yet in the set that has the highest/least weight and mark the new vertex as being in the set. Naive implementation has O(V^2). You can also use Kruskal's algorithm in O(E LOG V).
  Kruskal's algorithm: start with a forest of one-node graphs and a list of edges sorted by weight. Process edges in order of minimum weight, add the edge to the graph (and update the forest of graphs) if the edge connects two different forests.
  When it doesn't matter which value we used last, we don't need to keep the single state in pes dp.
  If some value doesn't depend on the order in which the elements were added to the set, but you can calculate it from just the state on the fly, then you don't need to keep it in the state.
  By keeping a second bitmask array, you can backtrack your way through whichever item was added last and in this way reconstruct the whole sequence (keep an array int best[1<<20] and int last[1<<20].
  In a DP program, if you're using bitmasks and toggling bits to get different outputs, make sure you process the masks in such a way that whatever mask you query has already been processed.
  Backtracking is a way to do all possible permutations of something (like next_permutation does). Pes DP is where you don't care exactly how something happened, or it cannot affect the result, or you only care about the best outcome of a range.
  Sometimes when you have things in a queue and you only want to know whether it is at some point empty, you can just use integers instead (representing the weight of the items in the queue) to perform a simulation that runs orders faster in practice.
  You can do the transitive closure taking depth into account (see above code sample).
  When the problem specifies that you need to calculate the distance from one specified city to one other specified city, you don't need your dp program to calculate the distances between all possible pairs of cities. Simply write it so it has a city and a length, and the length is then the length from the start city toward that city. And then your answer is the max of dp[x][endcity].
  DP problem where you don't care about which states you visited, just how many of them: have a dp state with city and depth. And then have depth iterations, where in every iteration you extend the thing by one distance if it is optimal. This is a way to build "minimum cost to get to place x in y steps".
  
  
  --- 16-08-2014
  Maximum independent set problem: in a graph, find the maximum number of vertices that can be selected such that there is no edge both of whose end vertices are selected. This is NP hard, but easier solutions exist when the graph is not the general graph.
  The maximum independent set in a bipartite graph is the number of vertices - the maximum matching (maximum flow). In other words, it is the number of vertices that are not connected plus the number of edges (half the number of connected vertices) in a maximum matching of a bipartite graph.
  If it's a bipartite matching but we don't know in advance which elem is on which side: see if there are properties of the graph that limit which nodes nodes can connect to. If it is such that a graph always forms a chain, simply throw even nodes of floors in one set, and nodes of odd sets in another set. If the graph forms a circle, do the same, but leave out one floor always. Linearly iterate over each floor and take the max to determine which floor is the best to leave out.
  A MBPM maximum bipartite graph mapping is simply a mincostmaxflow network, where there is an edge from the source to all left nodes, from all right nodes to the dest, and from a left node to a right node if there is a connection in the graph. Then return the flow result. You don't need back edges. Also, you don't need to specify a cost (the second argument to addege). This is only important when the answer is the cost of how many edges need to be changed (or what is the cost) (instead of how many paths can be used). Sometimes in these cases you want to specify different costs per edge as some edges may be free to use and others are not.
  Careful about your initial state for a dp problem. Usually it's just a single state (for example, if one aspect of the state is flying, you can't start flying, so don't set that to 0). The starting dp state can actually be one that lies outside of the answer range. That is, the dp[cur] state that you start with is actually the state before the 0 state.
  In DP state, there can be states that are not possible and are still the initial value (e.g., -1). So whenever you fill out a state that uses previous states, check if any of them are -1 and don't use them if they are.
  When you think that you have to go all possible order permutations of a set in order to see which distance is shortest (or something), you can apply Pes DP. That is, keep the set of places visited in a state and the last place visited. And then just travel between states.
  If you have a grid and only special points are of interest, precalculate the distances between those special points (e.g., when there's gifts on a grid, precalc the distances between those gifts and precalc the distances from start and end to those gifts).
  When doing Pes DP, make sure to use the dp value in the next state. When doing a bfs, make sure to update the seen state when pushing the thing to the queue.
  Pascal's triangle, or p(k,n) = p(k-1,n) + p(k,n-1) is equal to some form of the binomial coefficient (e.g. bico(n+k,k+1)).
  When you have to calculate bico(n,k), and you know that both n and k are very large but within a small distance of each other, you can calculate it more easily. E.g., bico(n+k,n-1) with n very large and k very small, is (n+k)!/((n-1)!*(k+1)!). You can calculate the (n+k)!/(n-1)! part by starting with n and multiplying it by n+x, with x ranging from 1 to k inclusive. The /(k+1)! can be done by multiplying by the inverse of the factorial.
  With probability ranges, sometimes flipping the signs so that they do the exact opposite of what they should do gives the right answer.
  If you're calculating the probability or number of ways of a row that contains 3 out of 5 numbers: multiply the number of ways to choose 3 out of the 5 winning numbers (C(5,3)) by the number of ways to choose the remaining 2 out of the 500-3 losing numbers (C(500-3,2)). Then multiply by 5! to get the number of sequences. Then multiply by the number of rows where this can appear (N). Then multiply by the ways to arrange the remaining 5N-5 numbers (=(5N -5)!).
  ! If you have a problem where you need to calculate some probability of something happening, see if you can determine it by using bico and calculating the number of ways that something is possible. Note that here you also have to take into account all ways where the numbers that you're looking for don't change, but everything else around them does.
  When you swap columns, make sure you iterate over the columns (and that the idx variable you pass through corresponds to the number of columns, not the number of rows).
  Number of ways to split up n objects over k groups (some of which may be empty) is C(n+k-1,k-1). Since the order is fixed, we only take this thing, and don't have to multiply by n!.
  The second argument to C(n,k) is the number of separators. The number of actual sets is one more than that.
  C(n+k,k) is the number of ways that you can put k separators between n objects (to make k+1 sets, some of which may be empty). Is also the number of distinct sets of exactly k objects if repetition is allowed.
  C(n,k) is the number of distinct sets of exactly k objects if you have n distinct objects.
  If you're increasing a minimum variable and you want the values in the resulting array to increase, then you must make sure that if you pick a value, that you update the minimum to that value as well.
  If you want to know all possible sums of 4 numbers, just condition their inclusion on the bits of any number between 0 and <16.
  If it says that you can change digits to make it like another number, you should not compare with numbers that are larger. Because it means that you can't add digits (but you can set others to zero, so comparing with smaller numbers is allowed).
  The number of unique pairs when you have n of something and you can't pair something with itself is n*(n-1)/2. If you are allowed to pair something with itself, it is n*(n+1)/2
  Removing all occurrences of a character from a string: s.resize(remove(s.begin(),s.end(),'0')-s.begin()); making a string unique: s.resize(unique(s.begin(),s.end())-s.begin());
  ! When you have a function where you need to return the nth number that satisfies some condition, use backtracking, use an idx argument where it is the length of the number, in each recursive body treat numbers from low to high, and whenever you reach the end, decrease the global class counter that you set at the start to n: when this counter is 0, store the backtracking state as your answer (SRM 464 DIV2 500).
  If you need to verify that none of the products of consecutive indices of a string of a number are the same, just do recursive, and in each index you add, walk backwards from that index to zero and each time multiply by the number.
  When you do BFS and the cost of a path depends on what path you previously took, then keep some state in your cost/seen array.
  When you have a range of numbers and you are looking for the pairs of additions that have with the smallest products, it's the biggest and smallest consecutively.
  If you have like addition or multiplication operators between numbers and you want to figure out the optimal order, or whether a greedy approach is possible, put your assumptions into formulas: (a+b) * (c+d) >= (a+c) * (b+d) and see what works.
  ! When things vary over a large dimension, try 3 things: 1) square root, 2) if the dimension is one of the input points, then see if we can get by by only checking the values at the input points, 3) binary search.
  If in a rec segment, the available range of each subsequent element is a superset of the available range of the previous element, then to determine the number of distinct combinations, you can just multiply by the available range minus the number of elements you had before. Because we don't need to know which elements were taken if we know that all of them have to be subtracted. If this was not the case, then we'd need to have a way to remember which elements were taken so that we can calculate which elements are still selectable by the current index. If we only need to know how many we can still select, and we know that each next index can select a superset of previous elements, then we can exactly calculate without needing to going through each elemetn multiple times. The key is: the number of elements selectable by each index is always the same. That's why we can do it in one loop.
  When you are modeling the swaps in a probability procedure, calculate in differences. As in: the score changes by the difference of the element you lost compared to the difference of the element you gained. You don't model it as 1/x part of a weighed equation between all parts in the jars.
  If you call your rec function in a loop with essentially one step already done, don't forget to pass 1 as a counter argument, not 0.
  ! There is only a point doing DP instead of recursion if memory is an issue. If memory is not an issue, recursion is usually faster.
  Negative modulo is just the positive modulo with a minus sign in front.
  Distances between two indices a and b in a cyclic array of size n: (a-b+n)%n and (b-a+n)%n
  If you have strings, then instead of looking at every index, it is about 4 times faster to do string.find and string.find_last_of.
  When you can only go two directions, and you need to match some character, then obviously a greedy approach where you match either of the two characters will work. Because you can't go to any of the other characters without having matched those original two characters. So there is no point in looking for the rest of the characters.
  When you use map lookups in your inner loop and you want to know how it affects complexity, just do $calc(0.5* $log(size of map) / $log(2)) and multiply that factor by how many times the inner loop is executed. It doesn't matter the map lookup occurs twice, since the total complexity will still be that.
  When you want a permutation mapping, don't use a map to map permutations to indices. You can calculate it using the permutation itself. (Not sure if this is faster).
  When you have a probability problem that potentially seems to go on forever, and the state is such that you can't hold all values in memory, here's what you do: use dp instead of rec so you don't have to memorize all the states.
  If you are only interested in the min cost in your mincostmaxflow network, you probably want to set all capacities to 1. If you set all capacities to 1, max flow means that it will try to connect as many things as possible. Min cost means that it will connect the path whose edges have the lowest sum cost to use. (But the max flow thing takes priority over min cost)
  If it is such that you need to assign to each employee a distinct skill (this is an instance of the assignment problem), and you can define costs for all, think about mincost max flow.
  If you have a case where if you hire one of them you get half benefit and if you hire both you get double benefit, you can treat them independently (instead of in pairs), and just increase the half benefit for everyone that it can be paired with. That way, when both are included, we will have full benefit. Note that this only works because the double benefit and because we are not talking about strict pairs, just whether or not two people are both in or not (the effect of which we were able to split up into the singular calculations for both).
  When you have a calculation involving a signed type and the unsigned version of that type, the default result (and intermediate calculations) will assume the unsigned type, unless you explicitly cast it to the signed type or the result is the signed type. The casting should never go wrong since both types have the same size.
  Rangecheck: if (max/i >= i) // valid  (if i*i <= max)
  For unique pairs, the value just needs to be larger than the current value (so triples are always ascending. Nothing else.
  Instead of doing while (i<sqrt(x)) do while (i*i<x). Note that while (x/i > i) does not have the same meaning since it throws away the things by rounding. You can only use while (x/i >=i) if the condition is <=.
  Instead of dividing something by 2, do the other thing times 2, wherever possible.
  If you construct hexagons and take just one path, you will still generate all possible combinations using dp/rec. This means that for rotation invariance, you have to divide that number by 6 (a constant). The start point is not special, in fact: if you were to repeat the experiment with multiple start points, you would end up with identical sequences. It looks at the end result, it does not matter how you got there. Can we get each possible end result by just always starting in the same position? -> yes. Complexity is manageable since it is 9^7 ~= 5mil.
  In rec probability, every step has to add up to 1 probability. So if you take the max every time (instead of the sum), you don't need to do that times a probability of choosing that branch, since the probability of you choosing that branch is 100% (as you ignore the outocme of all other branches). Only if your answer combines the answerse of multiple recursive calls, do you need to include probabilities of choosing each branch, such that they add to 1.
  In a two player game rec state, the player is never part of the state. Just return 1-rec(..); if it is the other player's turn (and you return a probability of winning).
  If you want to know all of the positions that are indistinguishable from a certain position, it is not enough to simply take the AND of all bitmasks that that position appears in. Because if there is a position where the original position does not appear in but the other one does, then they are actually distinguishable, but it will return that they aren't. Likewise, you can't simply do the AND of all bitmasks that one of the bits occurs in. Because then one off-bit will distort the results. The only way is to iterate over all positions and check if one of them is valid in some mask where the other isn't.
  If it is 2.5, you can use 2 cuts to get 2 elements > 1 and a remainder that is < 1, but you can also use one cut and get 2 elements > 1 with no remainder. So then with one less cut you get the same amount of elements > 1.
  When doing binary search and l and r are doubles, don't iterate until r-l < 1e-9. Just do it a fixed amount of times (like 100). Because: this may give errors on topcoder (and not locally) because of system precision or something weird.
  When you have a backtracking vector that you want to sort in the base case of the recursion, copy it first so it doesn't change everything else.
  For large data sets, knowing the probability of each question being answered correctly is enough to calculate standard deviation with dp (see TestScores). We pass on the number of questions correct as a parameter to dp so we can sum over the results which is the squared difference between the number of questions answered correct with the mean (that are composed with probabilities to factor up to 1). Then take the square root at the end. You simply have all possible outcomes, weighted by their possibility, and for each outcome you calculate the variance as (mean-outcome)*(mean-outcome).
  
  
  
  
  --- 02-05-2014:
  To calculate all possible pairs of lines with at least one space between them, calculate the N lines, calculate bico(N,2), and subtract the number of adjacent lines.
  ! Use binary search when you have a big range and want to find the minimum value for which something can be done. OR: when you know it may or may not be done for one value, but the results for the other values tell you in which direction to go (like they're either smaller or bigger than the number you're looking for).
  If you get segfaults, check your loop indices and check the statements where you create the variables to make sure those sizes match.
  Sometimes with rec the state seems impossible because you do 3 recursive calls in each recursive call and the size is 50. In these cases, you can sometimes reduce the state, e.g., by instead of remembering every specific combination or score, just remember the difference, things used, things borrowed up to now, etc. Then more states will overlap. And then you check whether you get a valid state at the end. Ask: What do we know about the end state, what needs to hold in order for it to be valid? And only include those properties in our state.
  The number of 1 bits that need to be "moved" is half the number of bits in difference. Or: the number of bits in difference*2 so that you have that number of moves.
  The gcd with more numbers only gets smaller. So it is like a precision (note that it is always smaller or equal to any number in it): we can reach every element gcd distances apart and nothing else.
  When you have a state with 2 counts, i.e., one counts to zero and the other only decreases by one if the second is 0 and then sets it to its original value, the second counter acts as extra lives. So the extra lives counter should be one less than the total amount of lives played.
  Hamiltonian path: You have to visit all cities and can only visit each city once. Meaning no city can have connectivity >=3, and there can be no cycles (for paths that have to be visited). The nodes with edges that have to be visited can then be split up in connected components, and these connected components can be traversed in two directions (times 2 for every connected component of size > 1). Then times the factorial of all connected components (because they can be placed in any order). Note that we don't use bico here: you only use bico if you have to leave stuff out or leave stuff empty. 
  Check if assignment specifies absolute values. Always check limits for constraints, even for 250 point problems.
  Dijkstra: have a seen boolean state. empty. have a priority_queue with 1 item. start loop. Inside loop continue if in seen. Then check if endstate and return. Then add to seen. In the loop only add if not seen. Cost is part of state in a pair.
  If you defined == and <, and you want to use != and > in your code, you need to explicitly define those too (check if you can use them without defining anything (no you cannot)).
  In probability recursion, you can have that the total in the recursive body adds up to more than 100%. This is fine as long as you divide it by something (like the total number of calls). Now if the complexity is such that you'll have to use dp, you need to pow() calculate the total number of cases. If the average prob per call is 3, you need to divide the whole thing by pow(3,depth) to get probabilities between 0 and 1.
  s.substr(spos,idx-spos) if you don't want to include idx.
  If you have an empty string, it will not return .eof(), so check if a string is empty if you parse it with a stringstream. Otherwise you might get errors in topcoder (not locally). Also if you read it into a string, it doesn't read spaces, so when a string is just a concatenation of spaces, .eof() will not return true and you will read an empty string.
  If there are only 15 items, with memoization you can calculate removing at each step every possible value that is still remaining, because a lot of the stuff is overlapping.
  For a progression of numbers where each is formed a*previous+b, when you have one number, a and b are ambiguous. When you have two numbers, the series is ambiguous if they are not the same. Otherwise a is 1 and b is 0. If there are more than 2 numbers, a can at most be the maximum range between the numbers. You can figure b out from the third coordinate. Because with two coordinates, you can make the next one be the previous one+1, but then the third one will increase by at most a. Since both second and third will have to be in the limit, this bounds a within that limit as well.
  ! When you have a range problem with overlapping and intersecting ranges, the sought out returned point is either the start or end of one of the ranges under consideration. So it is enough to simply iterate over those numbers rather than to calculate all the intersections explicitly.
  When the events are not mutually exclusive (e.g., the payout for slot machines), it means that we don't have to worry about overlap, we can just add the expected values. This is probably a rare and exceptionally easy case.
  You can do accurate == 0 checks with doubles. They will not be 0 unless one of their terms is actually 0.
  Check the problem description carefully which edge cases take precedence if they may overlap each other.
  The 1e-9 offset is always in the direction of where the majority of the values lie.
  ! If you want all distinct combinations where you need to choose 3 out of n for example (3^n), do this in a single recursion over n, keeping a togo counter. If the ordering matters and differently ordered sets should count as different outcomes, you use backtracking instead (n!).
  You use backtracking when the order of selected elements matters, i.e., when different orderings of the same set should count differently. Otherwise, you use simple recursion over the idx.
  In a recursive function, when there are n recursive calls in the body, and each has a depth of m, the complexity is n^m.
  The difference between backtracking and simple recursion is that in simple recursion your depth is the (number of elements) while in the loop body you call the recursive function (number of possible choices) times. In backtracking you loop over the elements and the depth is the number of possible choices.
  If you need to go over all possible ways that anyone can win (and save the results per winning playing in a global array), then this can be done with backtracking.
  ! If a state is comprised of 2 things that operate independent of each other, you can split the state and precalc each part.
  If a state is such that one guy has to deliver everything that the other guy doens't deliver, you can just calc for all possible subsets, and then take hte min of the max of each mask and its inverse.
  If you need to compare a double to an integer range, conver the integers to doubles rather than rounding the double to something.
  If you have a bool array and a double array, their sizes can be 2400*2400 max. (2500x2500 is too large)
  ! If the bounds of your next jump depend somehow on your previous jump, then you will have to use a recursive function with a state. If the distance you jump is the same for every single jump, you can use a big array of all outcomes and iterate over it as many times as there are throws. This is not trivial if you can jump different lengths.
  If two things have nothing to do with each other, (e.g., two identical things, both need to be brought to zero and don't affect each others outcomes in any way), you can reduce the state by precalcing the probability of the outcomes for each of the two in an array, and then run over the array once to add up all the events where one prob is bigger than the accumulated prob of the others.
  When you do 1<<something, then you get all subsets of size something, but you also get each something can be above or below the line. This will include all mirrored sets. So if the things mirror themselves, you can make it > 1 by flipping the two sets, but that set is already present in the amount of subsets. So in fact you can make all subsets pass the test, but if you do, half of them will have been doubles, so in fact half of them you don't count.
  If a problem is: return the minimum required, and you can test whether something is possible in a certain amount, then do binary search, especially when the range of possible values is > 100,000,000.
  ! If you have a range of > 100,000,000, you know it's either gotta be some squared operations or binary search.
  If you have a two player game and a certain board has a winner, then the first player that can change the order of the winner will win.
  If the probability is the probability of a single event, the expected value is the cost of a single event. If the probability is in the form of event 1 or event 2, i.e., p1+p2, with p2 not happening if p1 happens, then the expected value is calculated as an expected value that should take conditional probabilities into account. That is, if something has 20% of happening and it doesn't happen, the remaining probabilities become larger with a factor 1/(1-.2).
  ! If you are given probabilities for p1, p2 and p3 and it is said that one of those 3 will happen for sure and those events are mutually exclusive, once we find out that p1 doesn't happen, the probabilities for p2 and p3 become bigger so that the sum is 1 once again (if needed include (theoretically) an event which says "thing doesn't happen").
  At the calculation of the expected value for an event, you don't need to take into account that the event might not happen at all. You just assume that we got here and still have to have the event and then calculate the expected cost. Because the event that we the event didn't happen is treated separately and also taken into account.
  If you call your rec function multiple times with one step already precalculated in the initial states, that means that your loop has to run 1 less time.
  50000*50000 is above INT_MAX (46340 is the limit)
  For O(n log n) Dijkstra, you still need a seen state, but it doesn't contain the distance, it can just be a boolean as to whether you've seen this or not. (See ExpensiveTravel for good Dijkstra impl).
  When you want to calc the expected value of (X-Y)^2, think of writing it out as a full formula and calculating the terms individually as constructed sums. (X-Y)^2 = cnt*X*X + sumYsquared - 2*L*X*sumY.
  If something may not exceed 2520, it can still be 2520, so the number of minutes you should return is /2521.
  Your standard idx+1 rec converted to dp: outer index is idx and counts down from n to 0 (inclusive). return dp[0][k] (the same parameters as you would give the recursive function).
  Sometimes you don't have to put something in a state: you can also calculate it in a loop in the recursive body. This may be better if that specific variable is not eigen to the state, but rather it is only used to easily calculate the next state.
  Other way to check for overflow: if INF/z < res "overflow" else res*= z; INF is the maximum allowable value.
  To test for overflow on multiplications, check if (x*y)/y == x. on addition, check if (x+1) > x.
  If you have to find max triangle area with all integer coordinates, you can calculate all possible sides (which are the sums of two squares). To calc the sums of two squares, you only need to run an index until the square root of N, because you don't look at that index, you look at the square of it. Then do a test whether N-i*i is also a square root.
  The integer conversion of sqrt(N) when N is a square number is always exactly an integer, you don't need round.
  ! When you do coordinates in one dimension, the thing you add is always m, the second size, not the first size. So: i*m+j.
  When you do modulo, always make sure the thing is positive (add the amount that you're moduloing over). Note that even a calculation that only contains pluses can be negative (e.g., when one of the variables being summed over can be negative).
  You can check whether something falls in all gaps by just checking if the integer division of the start+1e-9 is less than the integer division of the end-1e-9, for each gap. you do need the rounding precisions here because the idea is that if the jump is exactly the gap, the rounding precisions make it so that start and end are still the same integer.
  If an interval has the start of a gap as an endpoint, there is a smaller interval unless it also hits the end of a gap.
  When you're looking for the shortest number of moves to get from some start state to an endstate and simple bfs is too expensive, you can sometimes shorten the search by doing bidirectional bfs, where you have a queue and set of seen states for both sides that you keep swapping and then the minimum distance is the iteration number where one state from the left meets one that is seen in the right. See HanoiTower.cpp for an example.
  Never do an (i == j) check with graphs unless you know exactly what you are doing.
  You can do an inverse floyd warshall (minimal inclusion) using original floyd warshall (counting each added edge double) and afterwards per node only add edges that have a dist of 1. Because those apparently were the only ones that were essential.
  Rotate a grid: H[51-j][i] = G[i][j];
  You can avoid having to call a function multiple times by having just one stopping point in your recursive algorithm.
  Maximum recursion depth is around 64000. Always check limits for every call of a recursive function.
  
  
  
  
  
  --- 17-05-2014:
  If you have a recursive function that returns the max, and some functions return -1000000 as error value, the default value shouldn't be 0, it should be -1000000. Because if wrong solutions are the only solutions, you'd end up with a value of 0, which may be used in a correct result, while it shouldn't be possible.
  Unless you're dfssing over a tree where you will never deal with nodes more than once because you can't go back, dfs NEEDS a seen state so that you don't handle a node more than once. Simply having the requirement that one path never visits the same node more than once is not enough because at each node you can intiate multiple paths that have overlapping subpaths. You don't need this for a tree because you will never handle a node more than once because there's only one way to reach each node.
  If something is left or right, and you have a third case that calls both left and right, you can probably remove it and just start on one of the sides arbitrarily.
  You can't calculate the average with a dfs-like approach. It will weigh every branch equally, not every node equally. So just return the total and divide that by the number of nodes.
  Things with a sliding window (histogram) you can also maintain as just an index into an array where it says how many we have seen until then (as a sum) and then we can calculate the occurrences in an interval in constant time.
  When two terms in a system of linear equations always appear together in the formulas, you cannot distinguish between them.
  Even when the lhs is a double, when you do division, make sure at least one of the numbers is a double.
  Sometimes when you have things in two dimensions, you can make it easier by going over all possible subsets of one dimension first and then handling the other dimension in those cases. (If you can split part of the state and calculate it independently, do it).
  If the lcm of a set of numbers has to come out to an exact number, then every number that is in that subset must be a divisor of that lcm.
  If states used items in the past don't matter for things in the future, don't include them in your dp state.
  Even if your state is manageable, e.g., [1<<15][101], note that operations inside the rec() function also count towards the complexity. So if you have a linear loop with n = 50 inside that rec function, you will still exceed time limits.
  The mod of a long number is the sum of the mods of its digits multiplied by their bases (1, 10, 100, 1000) etc. Note that you should can just mod their bases by the same number.
  Palindrome as a dp problem is just approaching it from both sides and making sure that the ends are equal. The other way (where you have to calculate the minimum number of chars to add is by determining the first whether the substring starting at increasing index (from 0) are palindromes.)
  if you do abs(words[i].size()-words[j].size()) somewhere, note that this will give integer overflows because the result cannot go negative. And you won't solve it by casting one of the things to the signed type, you have to cast both or the result.
  Using a map is not feasible if you have 2600 states.
  When your state indexes into a substring, it is an order of magnitude faster to save the state as integer pointers into an array than it is to save the actual string in a map. This can be the difference between 8 seconds and 0.07 seconds execution time.
  When you have to return indices from a string that is too large to iterate over or hold in memory, do the following. If the number of repetitions per string is 1, compute the answer as either in the input or indexed into repeated suffixes modulo something. Otherwise, the string grows at an order of 2^something.. so holding all sizes up until a certain size only holds log(n) things. store all sizes, then call a function that iterates over programs.size, and for each i subtract the size of that iteration, only step into things when the index would get negative otherwise. Model only up until either the size of the current string > max or until the sizes iterations is <= the given number of iterations. It is important to start at the highest level with the full index and every time decrementing the index until it is in some range. So in summary: cache the lengths and iterate over repeating programs until i is 0 or there are no more levels of input. This iteration is only log(n) or better complexity when the number of repeated substring pattersn is at least 2, so when it's 1 this reduces to a simpler pattern where we can consider modulos (don't need recursion here). In both cases, handle the calls for each index separately (assuming the number of index is a constant << n).
  If you need to consider all possible connected components of a tree, it helps to reorganize the tree (with dfs) so that it follows a hierarchical structure. Then in every iteration consider all path lengths of a certain node edge thing.
  When you initialize a double to hold a minimum value, initialize it to something like 1e100.
  To check for LL overflows when using pow: if (pow(iroot,i) > LONG_LONG_MAX) break;
  As soon as pow() exceeds 1e15 (the precision limit for doubles), you may get rounding errors when converting to long longs even with exact arguments. You need to use pw (and possibly exclude cases where pow(iroot,i) > LONG_LONG_MAX).
  You can do the sqrt of any order (e.g., cubic root), by doing pow(n,1/3).
  With rec+mem, you often don't need to handle the exceptional cases (-1) if that is the default value by which you initialize the body in the recursive function.
  To make any possible permutation of a string of length n, you need at most n-1 swaps.
  Sometimes it is not enough to swap x and y and say x is always the smallest item. Namely, if you only swap them based on the first value that differs, and you don't have enough swaps to account for all the values, it may be that you can't compensate for the remaining values. There is no easy way to do this in one function other than calling it twice with the input swapped.
  When you go over different connected components of subtrees, when you choose an edge, you implicitly remove it from that tree, which also means that in subsequent iterations of the same recursive call, you may no longer use that edge. You're basically saying, when i enter this edge, i am considering all possibilities that include this edge in some way, so that I remove it from the tree after. This means that subsequent calls in the same recursive function may no longer use that edge because we've already considered all possible combinations that include that edge. So once you treat an edge, include it in the "dont use" set, and never take it out of it again.
  When you iterate over all possible subtrees of a tree, simply pick one and then multiply it times the number of edges in the tree without that edge. You will get doubles unless you exclude previous ones with every iteration of the loop. And then you don't even need to do bico things because you already include all the possibilities.
  ! The probability of marking 1 new bird can be found as C(unmarked,1)*C(marked,4)/C(marked+unmarked,5).
  When we have the rotations of a string, we are only interested in the divisors (which we can find in sqrt(n) time). Then, the answer is basically modPow(k,divisors[i]) but we substract all the combinations that were found in earlier divisors by subtracting all those if they are a divisor of the current divisor.
  You don't need to write one function to add two strings and have other code for adding an array of strings. That's redundant. If you only add two strings at a time, the carry is never bigger than one.
  To get all possible sequences of all possible lengths: have 4 for-loops, one for start and end of both coordinates, one for step of both coordinates, then a 5th inner for loop that runs while all coords are within range and keeps incrementing the coordinates by their respective step sizes.
  To determine whether a number is a perfect square, you can use the floor of the sqrt() of that number and see if it equals the same number when you square it.
  When things are cyclic, you cannot use topological sort.
  To see if a string of length N is a concatenation of multiple identical substrings, only check for substrings of the length of the divisors of N.
  number%0 will give an error just like /0 would do.
  To check whether a number is a repetition of a string a certain number of times can be checked in O(n), by comparing each index with an index shifted n/k away, where k is a number so that n%k == 0.
  You can get all separations in straight lines between points in a plane using line pairs between all points and assigning everything above top point to collection A and everything below to collection B (top and bottom to A and B as well).
  PI in <cmath> is called M_PI
  ! When we have strings A + C = C + B, then B is a rotation of A.
  The expected number of targets getting hit is just the sum of the probabilities for each target of getting hit.
  If you have like a network of connections that scale with factors depending on their neighbors, you don't always necessarily have to do dfs with stuff. If the graph is small enough you can do simple floyd-warshall and be done with it.
  a/b*c without parentheses does not cause an overflow even if a*c or b*c normally would.
  4 does work iteratively.
  an int has 31 bits you can set, so for-loop goes up to < 31 (1<<31 is a 1 followed by 31 zeros, and (1<<31)-1 is 31 ones).
  a long long has 63 bits you can set, so for-loop goes up to < 63 (1LL<<63 is a 1 followed bgy 63 zeros, and (1LL<<63)-1 is 63 ones).
  If you swap values from a bucket that has too many to a bucket that has too few, the minimum amount if swaps is max(nrswapup,nrswapdown).
  If you do gcd with long longs, always make sure the gcd handles long longs as well.
  You can get the gcd of all items in an array by setting g = gcd of the first and then consecutively taking the gcd of the gcd so far and the next array value. Note: you won't reach a local maximum because the gcd includes all factors of lesser cds as well (otherwise there would be a cd that would be greater than the gcd by multiplying it with those gcds). So it can only take factors out in the iterations, which is fine.
  When you have your 2^50 problem, you can do that with recursion within time if the state is somehow restricted (like you are only interested in the sum of the values MOD 9. 
  ! You can often reduce the complexity of a problem by optimizing one dimension: instead of trying to find all rectangles and counting all characters in those rectangles, turn the solution around and for each cell count the amount of rectangles it appears in.
  
  
  
  
  
  --- 24-05-2014
  When you want to make a palindrome by only adding letters to the end, the middle part has to be a palindrome still for that to work. Think of it as the middle part iteratively getting shorter by one (i.e., s.substr(i)).
  When getting maximum node value out of a tree, with the second player trying to pick the min value, it is always the max of the leaves, since those leaves continue to exist in any subset that you create.
  When dealing with terms in formulas: simplify formulas such that common terms occur as least often as possible.
  Try to write the formulas such that you have an irreducible fraction on one side: yl'/dl', where yl' = yl/gcd(yl,dl) and dl' = dl/gcd(yl,dl). Then the other side of the equation should be written as a fraction as well, and the minimum value of its denominator is that of dl'.
  If you need to retrieve the nth smallest element where n is a constant: keep track of two multisets, where all items in the second set are larger than those in the first set. The first set has size n-1. the item you return is the begin of the second set. We have the template NthSmallest for this.
  If you need to have a compact array of "values that are > than the index", you can construct it by iterating in the reverse order (decreasing i). You can add one value to it every loop.
  If different orderings of elements gives different results: factorial (backtracking). If the ordering doesn't matter but the different element combinations elements do: 2^n (number of possible subsets, recursive with mem). If the only thing that matters is a single value that is the combined result (e.g., sum or product) of all values: dp O(n*k) with k being the amount of possible values for each item n (when stepsize is not influenced by state).
  When you have two sets of things and you need to find the optimal balance point, it is often found by iterating in O(n^2) time over all possible values for dimension 1 and all possible values for dimension 2.
  If you have different subcases, see if you can modify one or two of the inputs so that you don't have to copy/paste similar code everywhere.
  ! In optimization problems, when you have A that links to multiple B's, and B's that link to one A only, then the optimization should be to handle the most difficult B's first. Optimize for the things that link to one other thing in the final configuration.
  When you have a problem with dp where you have two things and they appear alone but when they appear together they have to be the same: you can jump over the together part and calculate it from bico's only and then only use the recursive calls for when they appear alone. By having rules on the ordering of elements, you can make it so that you only need to keep track of one of the sides.
  Watch out with overwriting parameter-like values in a for-loop in a recursive function that are supposed to count only for that recursive call.
  Watch out with if/else statements that something that you think is an else branch is in fact always executed.
  2^15 = 32,768 is the rough limit on recursive calls (above says 64,000)
  You can carry a large and complex (e.g. two dimensional) seen state with you in a recursive call. Just set it before recursive calls and then unset it after. So you only need one array to represent the state for all recursive calls. BUT, then you cannot use your defacto mem[arguments] states because they also depend on global variables. I.e., this changes the approach to backtracking.
  When trying to maximize the intersection of two rectangles, always pair small sides and big sides.
  When you do two dimensional distances and want to find a balance, the minimum always has the x coordinate of one of the values and the y coordinate of one of the values. Because when the number of points left and right of a chosen point are equal, the distance is the same on all those points. If it is not equal, the distance increases or decreases in a direction until a point is reached.
  ((a&b) == a) means that a is a subset of b
  When doing binary search in doubles for precision: if the pivot needs to be within a certain range, stop when the pivot stops changing, not when the weighted sum that is used to determine the direction of the pivot stops changing. Rather: set a max and stop then, because then the probability is reliable and you will never hit your precision targets.
  Number of digits in a number X: 1 + floor(log10(X))
  bico(n,k) can replace a number of recursive calls if all you care about is the number of columns painted and not exactly which columns you paint.
  Know when it doesn't matter (due to symmetry) which columns we paint and when it is enough to just remember the number of columns painted. DP for each number of x of newly painted columns, there are bico(columnslefttopaint,x) ways to select those, but then we also do times 2^(alreadypainted) columns that we have already painted to paint any subset that we havne't painted yet.
  If you can use bico, probably don't have to keep in your state which bits you toggled, just how many of them.
  If something depends only on two other things then to do all possible subsets you can do in linear time by calculating components and ordering them using in-order DFS. Then you only need to remember the first and the previous value to make sure that they don't conflict. NOTE: if something can have 3 connections, there is no longer a linear path and the problem becomes NP. (This is about a graph problem where you need to visit some roads and some cities but only once).
  If you know that each element is at most connected to two others, and you find those using dfs, make sure that you use in-order traversal to guarantee the correct ordering of the indices in the array (if you store them) (since you can start from any index). NOTE: if you push the elements to the end of a vector, for the first one: push one branch first, then itself, then second branch (if there is one). For the second branch, give a parameter that says that all those values should be preorder, for the first branch, give a parameter that says all those values should be added postorder. (then the only thing that can differ is that the list is reversed).
  When there are strict limits on the number of objects associated with each other, think of graphs and what those graphs might look like.
  If your recursive function's state can be called recursively (i.e., it can be called again), make sure that this never happens by presetting the return value to something high that will disallow recursion. This is probably allowed everywhere (since normally you don't call the same state from within the same state).
  The CDF for a sum of two uniformly distributed random variables is a line z = x + y in a 2d plane.
  If you know that certain bits don't matter for your computation, use a mask to set them to zero when you retrieve the mem state: LL& r = mem[i][xy&mask][b];. This reduces the complexity of your solution.
  When you have a longest common subsequence problem, and you also have the condition that a substring needs to be equal, just run the lcs like normal, and include jumps when both indices match one of the substrings being found. This way, you can reduce the complexity to: substring being found yes or no.
  When you have a twodimensional problem. Try all possible combinations for one dimension and then in the other dimension just try a dp approach for all options.
  cnt[v][s] = cnt[v-1][s] + cnt[v][s-v] When term v is added v times. So the decrease of the sum increases by v when the variable increases by 1.
  You can simplify a formula with < terms to <= terms by substracting one from all numbers and saying they're different numbers. You can remove the < from the formula and replace them by + terms of terms that are the difference, and again do like z1 + 2z2 + 3z3 + 4z4 + ... <= ... instead of x1 <= x2 <= x3 ... and x1 + x2 <= ... the term that occurs the most is equivalent to the smallest term of the series. So the approach is: to reduce to a DP solution, remove the <= restrictions so that you get a constructive expression.
  2^n-1 will give you n number of ones because 2^n is a 1 followed by n zeros (because 2^3 sets the 4th bit (because 0 counts too)). max int is 2^31-1 which is 31 1s because 2^31 is 1 followed by 31 zeros. so int has 31 bits you can flip (the highest index is 30 because 0 counts) and unsigned has 32.
  Max val is 2^(number of assignable bits) -1. which in binary is (number of assignable bits) ones. because 2^(number of assignable bits) is a 1 followed by (number of assignable bits) zeroes.
  You can save a dimension in your state if you only store booleans and one state dimension <= 32 (or 8 for chars). In problems where you keep solutions in a single integer to save state space, also keep the seen state per bit.
  With the recursion where nreq numbers are still equal to something (you can use this type of recursion when you have the restriction that certain numbers need to be smaller than or equal to some other number). Lesson learned: you multiply the recursive term by something if there are distinct ways of doing that action that lead to different sequences. You basically have 4 different cases: orig 1, one of them 1, orig 1, all of them 0, orig 0, one of them 1, orig 0, all of them 0.
  Embassy problem: we can't really stop early because it's modulo calculus and you would need to find a sliding window that contains all the points.
  We need to handle big weights first because big weights are the bottleneck: not every crane can lift big weights. You have things that are linked to multiples and the other is only linked to 1. Optimize the thing that is only linked to 1 (you can do everything in one iteration if you can add new bins in each iteration).
  When permutations are applied consecutively with a single shuffle vector that doesn't change, the max number of permutations required is the lcm of the cycle lengths of all indices (each index is part of 1 cycle). Imagine this as each number travels between positions until it is at its starting position again. So for 47 cards this is 13+11+8+7+5+3 = 47 = 13*11*8*7*5*3
  When you upscale something, make sure that you upscale the ranges for the for-loops too. You have to set twice as many values in the grid for each index.
  The minimum number of multiplications to get to a number if each number has to be a divisor of the current number is done in the following way: start with 1, multiply by 2 as long as it is < than the number you're looking for, and then add +1 to the answer (because the biggest divisor of a number that is <= to that number is that number itself).
  You can calculate whether you can get to point x in time y starting from point x by just keeping a set of all vertices that you can access at every step. Length of period of repetition is at most length of largest gcd which is at most 30.
  The KMP function only works when the whole thing is a repetition.
  An int has 31 (but your for-loop goes from 0 to < 31) settable bits in it (because its max is 2^31-1)
  When dealing with divisor problems, note that every number is divisible by 1.
  When you convert a recursive solution with memoization to dp, you can copy the logic directly, just make sure edge conditions work. Sometimes you have to let a variable decrease instead of increase. 
  When you have to solve a subset of problems, see if you can determine an order for the problems using math formulas. Then you can just use DP to determine whether or not to include each number (if the points gained depends on whether or not you include another number, otherwise just do greedy).
  If the answer is a long long, make sure your dp array is a long long too.
  When you're using a DP approach and something is said about being divisible, only store integers MOD something in the state to reduce state space.
  If you have a while(changed) loop, you can implement it with recursion if you do the recursive call inside the part where you would normally set changed to true.
  For splitting things up over backpacks, it's always better to do the big ones first (a greedy approach will suffice) UNLESS you need a set amount of items per backpack.
  Floor is different from integer division for negative numbers. floor(-7/2) = -4; -7/2 = -3;
  floor for negative numbers: (a-abs(b-1))/b, for positive numbers: a/b
  ceil for negative numbers: a/b, for positive numbers: (a+abs(b-1))/b
  When you have to count the number of subsets of a number of elements where each element is used only once, you can use backtracking to construct the partitions (their total number is equal to the bell number). Then you can use the "comparing a number with indices" subproblem to solve for each subset how many numbers it can generate that are <= a number. Backtracking works like this: for each digit, add a number to each partition or to a new partition, or do not add it at all. You have to keep just one array with size of the number of digits in memory, and also an int pn which dictates how many items are in the array. (You can also do DP instead of backtracking, it then works with subsets of bitmasks and such).
  Number of divisors with a certain %divisor between two numbers: int calc(int x, int div, int r) { return x / div + (x%div > r); } and then ... calc(hi+1,div,r) - calc(lo,div,r); == count x: lo <= x < hi such that x%divisor == a
  In problems that ask the number of valid values between two limits, it is often practical to simplify them assuming there is a top limit and the lower limit is 0. For example if g(t) can count the number of valid n such that (0=n<t), then the number of valid n such that: (lo=n=hi) is equal to: g(hi+1)-g(lo).
  An arithmetic progression is a sequence of numbers such that the difference of any two consecutive numbers of the sequence is a constant. A geometric progression is a sequence of numbers where each number after the first is found by multiplying the previous one by a constant non-zero number which is called the common ratio.
  When you count number of substrings, count them increasing and such so that they always include a certain character, that way you know all iterations pertain to different substrings
  When you have a string of length n, the number of distinct substrings of consecutive elements is (n*(n+1))/2 (= the number of different start and end indices for the substrings)
  If you have to do every move always, but each move has two options, you can model that with the bitsubsets. 0 = option 1, 1 = option 2.
  In the innermost loop of the dp state, just pretend it's recursion. The end condition of recursion are your initial values in dp.
  If the number of states is too large to store in memory, and there is one state argument that always decreases by 1 in your state, then you can use dp to calculate the values in order so that you only need to remember the previous state (cur, next).
  If you have to calculate the number of distinct pairs whose xor is less than a number, use dp, and just keep a state of whether everything has to be the same, or whether it can be any value because it was already smaller.
  If there's multiple options to do something, sometimes the solution is mbpm/max flow, where you consider the best combination of all available options.
  If you don't need to know the actual values in LL, just the comparisons, then do inline long long convert.
  When you are trying to implement a greedy approach, and you don't know which cell to fill first, don't consider steps as filling cells, but as removing elements. Turn the problem around so that you evaluate when you can remove an element, and do that in every step.
  Watch for when you copy a variable with the same name to class space, and then adjust the local copy of the variable.
  All possible subsets of 50 elements (i.e., 2^50) you can calculate that with DP if you can compress the state space in some way. For example, if you're only interested in the sum of elements, and we find that each element has size < 1000, then the sum always < 50000, so you can just iterate over everything. If you only use the previous iteration then, you can make a dp[2][50000] array that fits perfectly.
  Sometimes DP can do things that will run out of memory in recursion, because for recursion you need to remember all steps, while for DP, you can exploit the fact that you only use the previous step in each step.
  If you are comparing ratios, make sure at least one value corresponds. Do this by quadratically multiplying all values of one array by a value of the other array.
  When the problem deals with convolutions, the solution is almost always DFT.
  Often, variables in the state can be derived from other variables in the state. Then you don't need to include all of them in your memoization array.
  Counting the number of permutations in DP breaks down to counting the number of different ways to make one partition, and counting each possibility separately if there are different possibilities that affect the state/score differently.
  The factorial changes the ordering. If the ordering doesn't matter for the thing you are trying to calculate, if you need all possible pairings of two things, just keep one the same, and only look at all permutations of the other.
  Whenever you feel like doing a thing where you have a circular array state and you eat off the end and add to the start, you can also just keep the state the same, but rotate over the indices (lots easier). Then for example, i = state of the cell above, and if i > 0 then i-1 is state of the cell to the left. Actually, you SHOULD do this, otherwise the states for different cell indices have different meanings, and then you can't transfer between them (probably).
  Sometimes in dp you need to keep the number of combinations in memory as well as the state of the last row. Here, you can just keep the last row in the state (you don't have to modify it to rotate). And then you just keep all other values in the state the same. The looping over all possible states guarantees that all board positions are counted this way. Also, each time you just increase the dp index by 1, not by a row or something. You don't actually need the dp value from m things ago, just the dp value from last time will do.
  When you have two sequences that behave periodical in some way, plot them in a graph with x- and y- coordinates to detect patterns. (like a line bouncing off the walls)
  You can check conditions while constructing a dp array to construct the result.
  When you run dp to find the number of unique combinations, always make sure that the sets are different by doing like a double for loop with indices that you consider.
  You can reverse the construction of a dp array to get combinations that do not involve certain elements. Note that the indices have to run the other way around then too (so everything is done in reverse).
  Don't think too hard. If the limits are so small that a brute force solution is allowed, use a brute force solution. Your MBPM algorithm doesn't work with edge weights. And the Maxflow algorithm doesn't work when you want to leave one edge per node. In this case, ya gotta brute force it.
  The xor of two numbers a,b that are either 1 or 0 is (a+b)%2.
  When you get a problem where they ask for a <= solution, try to split the problem up into a smaller version and an equals version. And make sure that all solutions for the equals versions are different in some bit so that there is no overlap.
  Finding the number of subsets whose xor is equal to a certain number is like solving a linear system of equations. You can perform Gaussian Elimination on the matrix of coefficients. Then, 2^(number of free variables == the number of zero rows == number of variables minus the rank) is the number of different ways that the number can be reached.
  Note that if you iterate over the 1 bits in limit to find the xor subsets that are <= limit you do the equals version on all the prefixes with the last bit equal to 0. Since all those prefixes are distinct, all solutions gained will be distinct and you can just add them.
  If in a DP state, all things can move around and neighbours can be in different positions: work linear with dp and fix the position of the previous thing in the dp state and work with that. That way everything appears fixed. Don't worry about things coming after either, any invalid solutions won't be used. Your dp state will be the number of possibilities of having m elements with the previous one having position k.
  When your DP state has a zero case that you want to work like the rest, just do it in a separate loop before the dp loops, then run the dp loops one less time.
  When you have things moving in opposite directions, encode those as -1 and +1 for incrementing your loop variable and then run a for-loop with condition >=0 && < n.
  Your state is all the values you need as input for calculating a value.
  2^26 = 67.108.864 = feasible


 
  
  
  --- 31-05-2014
  Disjoint Set Forests: Use when you have a number of bidirectional edges between objects and you want to find out what the connected components are. We can also do this in O(n) using dfs, but this is faster. Remember, you only need to call links in one direction, and the order doesn't matter.
  If you need to make things a string of 1s, and you count the number of state switches as 1 toggle, then make sure that you end up with a string of all 1s, not all zeros. You do this by checking whether in all cases where you don't switch, you never switch in any step.
  If something is determined by its neighbours only, i.e., locally,  (and those neighbours have K values), you can iterate over all possible combinations in k*linear time using DP (you don't need to keep a state of everything, so you can go over all possible combinations even when string length is like 2500).
  The indices to string::substr can be read as a for-loop. So s.substr(0,i+1) includes all indices from 0 <= x < i+1. s.substr(i+2) does the remaininder of the string starting at s[i+2].
  If you're doing all pairs shortest paths by bfs/Dijkstra, then note that those are calculated n times (once for every point). So if you only need to know distances from, say, 2 points to all other points, you only need to call the whole bfs thing twice (once for each point). You don't need to calculate all the other values. Note also that this is not true when you use Floyd-Warshall.
  If you want to maximize the sum of 3 variables under some constraints, then let the state pes extension be ranging over one of the numbers, let the dp state itself return the (maximum/minimum) second number, and let the third number be calculated as the sum(of included elements in the set) minus the first and second number. Then transition between states if they are not in the current state like normal.
  You can't use a bool graph g if you're gonna fill it with -1.
  If you don't need to transform back to row/column indices, you can just use [i][j+N] and [j+N][i] as indices into a graph.
  Thales intercept theorem: if a set of lines is intercepted by a line and then also by a line parallel to that line, the intercepting segments have equal width ratios.
  The formula that the area of a triangle is 0.5*base*height is true for every triangle as long as the height is measured perpendicular to the base. Which means that you can only do this if one of the corners in the triangle is 90 deg (but every triangle splits into two of those triangles).
  In many cases, you can calculate the intersection point smarter than just writing out the full formula.
  Triangulation in 3 colors is not possible if the amount of Z (or N) edges in blocks of four cells is odd.
  Floyd-Warshall works with negative weights, just not with negative cycles.
  When some things are offset between nodes, you don't need to keep track of both a max and min, just of a min. when you have min(i,j), the fitting max is -min(j,i). In the initial distance calc just swap the indices. Your Floyd-Warshall should be an extension of what you already did in the precalc for the edges. Begin of the second minus end of the first is minimum, because the other way around is end of second - begin of first, which is obviously bigger.
  If you're counting segments, make sure there's at least a point in each segment (since the points defined by the function lie on connecting edges, those are only counted once). You can simply do this by making the map for all types, and then increase by 2 every time.
  Modular multiplicative inverse only works when something divided by something leaves no remainder.
  Modular multiplicative inverse is when instead of dividing something by x, you get the same result (mod kMod) by multiplying it by x^(kMod-2). als je iet's /b moet doen, dan doe je maal  b^(kMod-2)
  The greedy thing where you split the heavy weights up first only works if you want to get the most balanced groups but have the same amount of contestants in every group. If the task is just to balance by weight, you need to consider all possible subsets.
  When you need to calculate how many triangles contain all points, note that each triangle has 3 sides, of which one is also used in other triangles. So you can reduce the complexity by an order by precalcing for every possible side whether all points lie to the left of it.
  Since one has to be picked, the depth where bad stuff can lie must be > the max of the smallest depth for every type for the combination to be possible at all. Now, only when you handle them in sorted order is the one you select guaranteed to be the smallest depth among the bunch.
  You can compress a large range of values if you know in advance which values are relevant, and if you don't actually need to do any calculations based on them. If you still need the actual values in the end, simply convert them back.
  When you're working in a recursive procedure with a loop where you have to pick at least one out of n elements from a type in a loop and adding the results, the assumption is that when you get to index i, we already took into account any combination in which any index j was included, with j < i. Because in the current loop body we consider all permutations in which i is included (and elements > i). So in order for those not to have overlap, you need to do just like a quadratic for-loop and only consider the higher indices. That is the only way to guarantee that your permutations are necessarily distinct: all previous permutations included at least one j with j < i, so all the ones we consider now are different.
  Greedy works if when there are multiple optimal solutions, it does not matter which one we choose (or when there is only one optimal solution, or when all optimal solutions are identical). So for the lamps problem, we do not care about the state of the other lamps at all, so effectively all solutions that toggle the maximum amount of lamps will work fine. The idea here is that if a path you choose makes other optimal paths unavailable, then if had we chosen one of those paths instead, the current path would be unavailable. So we can only choose one and it doesn't matter which.
  In Dijkstra, only queue if the cost is smaller than what we already have (will save you about half the queue pushes). Queue the cost as part of the queued state and check whether the given priority != the current dist/cost. You don't need a seen for dijkstra, only the cost, check if given cost == current cost, otherwise ignore.
  This magic trick iterates (dx,dy) = (0,1), (1,0), (0,-1), (-1,0):   swap(dx,dy); dy *= -1;
  If all edge weights are either 0 or k (with k constant), you can use a deque instead of a priority queue. In other words, by the time you get to process the edge with +1, you'll have seen all the ones with zero weight already.
  Dijkstra is actually O(|E|+|V|log|V|). When the number of edges per v is a constant (say 4*V, in a grid), then dijkstra (for all V nodes) is actually O(4n^2 + 2 n^2 log n), which runs fast enough e.g., for 1600 nodes to do all pairs shortest paths. SO: You can do all pairs shortest paths dijkstra for 1600 nodes, but not floyd warshall (note: dijkstra requires a priority queue).
  You use a seen set when your Dijkstra uses a priority queue, because then, once you've seen a node, you won't need to see it again.
  All pairs shortest paths in a tree can also be done by lowest common ancestors.
  When doing modulo: if any term is negative, add the modulo
  anything > 10000^2 is too slow
  anything > 500^3 is too slow
  anything > 100^4 is too slow
  When you count in your DP state the number of permutations, if something can be in multiple positions, do dp[next] += nr_pos*dp[cur]. If something can only be in one position, do dp[next] += dp[cur].
  When you have the greedy problem of how to distribute something over even levels, do it with every subset >= some enemy strength divided by the count of people that can defeat at least one enemy in there, and return the maximum of that. The moment you can't divide it reliably anymore is the moment that another solution becomes the maximum.
  ceil(total/cnt): (total+cnt-1) / cnt;
  all_permutations and for every permutation all subsets runs in time if N = 8 max.
  (mask&(1<<i)) can actually be 4 or something, while ((mask>>i)&1) is always 1 or 0
  In pes DP be careful with how you initialize initialize dp[0][0] (or if you initialize that value at all, sometimes you don't want to).
  You cannot do pes DP when you can't merge states based solely on set membership and which one was the last. If you need more information (like when each item was added), you need next_permutation to iterate over all combinations instead. You can determine whether you need information by considering: if we know only which element was added last and the elements in the set, is different behavior possible?
  ! Iterate over subsets of a mask: for (int u = mask; u >= 0; u = (u? ((u - 1)&mask) : -1) ) (this includes zero and full subset).
  If it finishes in 2 seconds, it's fast enough.
  Expected value = nr of events * probability of event. Sometimes you don't need to know the actual linepieces.
  Sometimes you only need the histogram of values, not the actual combinations or anything (to determine whether something is possible)
  If you think a problem has properties of e.g. a minflow solution, think about how you can adjust the problem to it. E.g., 
  GENERALIZING: if the question is: is something true in all possible scenarios, invert the question, and answer: is there at least one valid scenario in which something is not true?
  When dealing with intervals, sort them and see if you can do it linear. Sort them by begin only and every time extend by taking the ones that you can do now and having the one with the largest extension to it.
  If you can come from left or right and also from above, but never pass a cell more than once (and we are interested in the max), do:  for each row, for each cell, take the value it had in the previous row and then for every cell to its left and to its right set it to the maximum of what it is + values added so far.   <--- X ---> for every X in the row increasing. The importance is not to use values that you set in that iteration.
  When you have values that vary over a large space, just identify events and only iterate over the unique values of those events and just loop for all fish over those.
  ! When the number of objects you choose is a constant, say 2, the complexity is not 2^n, it's n^2. Because you can't really choose all subsets, you can only choose subsets of size 2, which means you can only choose as many pairs as you have, which means it is quadratic. When choosing 3 elements, the complexity will be n^3, and so on. Note that this will never be 2^n, because 2^n means subsets of all sizes, not just of one specific size. So if it is asked to select a fixed number of c elements, the complexity is always n^c.
  When you have a graph and you are only interested in traversing between a subset of them, use Floyd-Warshall to get transitive closures, so that in your bfs you don't need to iterate over those nodes anymore.
  To use next_permutation(a.begin(),a.end()), first sort the array and then do { } while (next_permutation(...));
  If the total number must be even, just do 2^(even) * 2^(odd-1) -1 where odd is the amount of odd sets (-1 to exclude empty set). This is because even sets don't change the parity and when you generate 2^(odd) subsets, half of them have even parity.
  If you need to exclude the empty set, it is not 2^(n-1), but 2^n -1 (because there is only one empty set)
  If you are only interested in the number of maximally connected subcomponents, and you don't actually need the transitive closure for every node, then do DFS while keeping an array of used indices and be done in quadratic time (NOT Floyd-Warshall (O(n^3)).
  When you deal with a grid with Manhattan distances, transpose it by 45 degrees and double the number of points. Now you can treat the two dimensions separately with (x+y,x-y) points. The bounding box is now just a rectangle (in the original Manhattan square, the bounding box was a 45 degree angled thing
  You don't need a graph structure to do dfs
  A divisor doesn't have to be a prime.
  105 million steps is the maximum in 2 secs: 105.000.000
  When wolves start from different positions, but they all walk the same path, you only need to calculate that path once.






  -- 09-03-2015:
  When you can't keep track of which vertices you included, keep track of edges. When you use backtracking to stop early you can't use memoization/dp most of the time. Can also easily represent a graph with bit masks for inclusion/exclusion of sets.
  g[i][j] |= g[i][k] && g[k][j]; <-- works only with bool g[50][50], not with vector<vector<bool> > g(n,vector<bool>(n,false)) (it will not compile: gives a syntax error).
  if you calculate the expected value of shuffles as 1/probability, and it says you don't shuffle if you have hte same thing, then subtract 1 from each step where you increase the answer
  memset(dp[next],0,sizeof(dp[next])); when you have alternating states: int dp[2][51],  int cur = 0, next  = 1; REMEMBER if you use a state like this you always have to reset it in every loop iteration.: swap(cur,next) at the end of the loop, and then   memset(dp[next],0,sizeof(dp[next]));  at the start
  When there's different recursive paths you can take (either pick object from set A or one from set B), always execute both paths and add the results (or take both paths and take the minimum of the results). Never just choose one path if it is possible and go that path only. Because the recursion is about being able to do all those things at that time and the results should reflect that.
  Can only calculate the surface of a triangle between 3 points if they are given in counterclockwise order (i.e., their cross product is positive).
  const double PI = acos(-1);
  binomial coefficient with mod you use the modinverse.
  Let us define a number as the product of all prime numbers each raised to an exponent. 12 = 2^2 * 3^1 * 5^0 * 7^0 * .... Then for another number to be a divisor, each of the prime factors must have an exponent less than or equal to the exponent for the same prime in the first number.
  Number of divisors when you have prime factorization: 12 = 2^2 * 3^1  = +1 for each factor and then times and then -1 to exclude empty, so (2+1)*(1+1)-1 = 5.
  first occurrence in binary search, you need different algo: where r is set to the pivot and l to pivot+1, and while (l < r) then return the r value at the end. So note that your default way of doing binary search is not guaranteed to return the first match when there's multiple matching elements. It's simply a matter of, don't immediately return when you find something, always execute the full search.
  If you get two vector<int>s, together representing edges, you can create an adjacency matrix from this.
  
  
  
  
  
  
  
  -- 11-03-2015
  Permutations (if dp is involved) can also be done with bitwise iterative subsets. just make the inner thing be a double for loop, for which the outer for-loop you don't check whether it's actually in the mask (actually it should be in the mask for all except the first value, but here it doesn't matter since what you add or loop over will be empty). Only of the inner one. check pes 900pt srm 562 div2 <-- YUP, see all_string_combs3.cpp
  When you have something with order (permutations/subsets), the order doesn't actually matter, just the subset (as an int value) and the x elements that you picked last. Save all of those in the state, use memoization and you're done.
  You can traverse a tree without going in cycles as long as the next one isn't equal to the previous one (emphasis on tree: this does not work for a graph with cycles). (otherwise just keep an array of "seen" nodes). and iterate and call dfs as long as there is something unseen. Note: ALWAYS check whether a node you visit is seen or not. 
  Expected value of sum is equal to sum of expected values.
  Floyd-Warshall: also for all-pairs shortest paths.
  sizes[state&(1<<i)]  <-- dit returnt niet altijd 0 of 1! want hij returned 2 als index 2 is. just terug transformeren of sizes[(state&(1<<i))!=0] gebruiken.
  The summation of terms 0, 1, ... K is    k*(k+1)/2
  The summation of terms 0, 1, ... n-1 is  n*(n-1)/2
  XOR with 0 is equal to the other number
  problem with linear combinations: always find formulas to solve the ones that occur in multiple formulas, then make sure all those counts are >= 0, then make sure that the ones that only occur in one formula also match the calculated count
  You can change a matrix in n^3 time (Floyd) to transitive closure if the problem concerns transitive closures (so you can calculate those in linear time afterwards). Create the transitive closure in a graph of bools like this:     for (int j=0;j<l.size();j++) for (int i=0;i<l.size();i++) for (int k=0;k<l.size();k++) g[i][k] |= g[i][j] & g[j][k]; The order is important here. The middle element has to be the outer for-loop.
  You do not need to initialize strings to "". They have that value by default.
  When something adds a special condition to the first or last element of a string, don't handle it in the recursive code by adding more loops or conditionals, simply handle it outside the loop. iterate the recursion over all possible values of that first or last value. Don't forget that now the recursive depth is now one less.
  The number of different strings you can get by marking k cells of a string of length n is the binomial coefficient of n and k (written n over k).
  To determine if something is a power of x: while (tmp > 0 && tmp%x == 0) tmp /= x; if (tmp == 1) ...
  string.substr(a,b) is the string after skipping a characters, of length up to b characters.. it is s[a] to s[a+b-1] (both inclusive)
    s[i] is directly after s.substr(0,i) and is the first character in s.substr(i)
    s.substr(0,i) and s.substr(i) do not overlap
  For checks on overflows in loops, do while (i>j) { ...; j = i; i++; }
  Setting a bitmask with multiple bits: dp[0][t][a|(b<<2)|(c<<4)|(d<<6)] = 1; then extract values with int d = (mask>>6)%4;
  If you have a state like int dp[2][8][256], you can clear part of the state by using memset(dp[next],0,sizeof(dp[next])), or using fill with fill(&dp[next][0][0],&dp[next][8][0],0);
  Remember: if you only need to remember about the last two states, you can keep state space down by doing a mod 2 on something, but you have to set the next state to 0 every time.
  With iterative approach: once you know the state, you simply iterate over it.
  When you have recursion that is a layer with blocks of 4, do recursion steps one layer at a time, and then in every recursion step call recursive function for all possible permutations of that layer. Also, don't forget to include 1 to count the current permutation as base result when adding over multiple permutations. For the iterative version of this program you would be doing 1 block at a time.
  When treating an int state as a number and adding something to the end of a queue: dp[next][j+add][(k>>2)|(c<<6)].
  sometimes with dynamic programming you don't know in which index the maximum result will be. In that case, you need to update the optimum solution inside the loop.
  if you have a%4 != 0 and b+c == a and b%4 == a%4 then c%4 == 0 <-- the a%4 != 0 condition is not needed
  sometimes you don't need to analyze the behavior of a function. Just write it as a function and treat it as a black box: call it with different outputs and see if they differ. Then see if the desired output % this difference == 0.
  fill memoization always with -1. -1 indicates not cached. fill dp with 0 (probably) and one of the values 1 or something.
  (1LL<<i) for long long bitmasks
  If you have a priority queue of ints or chars that you want in reverse order, just push -the value. remember, priority_queue (like stack) uses .top() instead of .front() and in a priority queue the items with highest priority are dealt first.
  You can index an array of pairintints like a vector: vector would be size BIG and indexed BIG = BIGG*BIGG as a[i+BIGG*j] then (i+BIGG*j)/BIGG = j and (i+BIGG*j)%BIGG = i
  Some algorithms with combinations that would otherwise be factorial n! (e.g., number of permutations) can be made to run in 2^n through dynamic programming that avoids the repeated recursive call. This will only work when the subproblems are overlapping and the problem has an optimal substructure. That's why it won't work for raid compositions: the substructure is not optimal. So while the total number of permutations is factorial, some of these are overlapping and you only need to calculate them once. The things you need to calculate once are exactly the number of distinct subsets which is exactly 2^n (because all subsets can be expressed as a binary number where 0 and 1 indicate exclusion or inclusion in the subset).
  
  
  
  
  
  -- 02-05-2014:
  If there exists a permutation T of the vertices of a graph G such that there are no reverse edges for T, then G is acyclic. (Topological ordering of edges). If G is acyclic and connected, it is a tree.
  When you have two sets of things and each is connected to several others, and you want to determine the most compatible pairs such that each vertex is used only once: Maximum Bipartite Matching: Can be reduced to maxflow problem when you add a super source and super sink.
  Area of a triangle: 0.5*base*height -- ONLY when it contains one 90 degree angle. But if it doesn't, you can split it in two triangles that both have one. You can calculate the height for each of the 3 edges so you get like max 6 distinct triangles in total or something.
  The Xor of numbers 1 to X is
   X % 4 == 0  -> X
   X % 4 == 1  -> 1
   X % 4 == 2  -> X+1
   X % 4 == 3  -> 0
  NEVER be smart with i < S.size()-3 conditions, instead use i+3 < S.size(). In fact, never substract something from a .size(). This will run forever because the negative number is positive. Only if you know that S.size() > 0 can you use S.size()-1 as a condition, but rather just alter the other thing.
  Sum of a range of intervals: keep a pair with opening 1, and closing -1 second val. then sort
    sort(m.begin(),m.end());
      int cnt=0;
      int r =0;
      for (int i=0;i<m.size();i++) {
        if (i > 0 && cnt > 0) {
          r+=m[i].first - m[i-1].first; // doesn't even matter whether i is an opening or closing brace
        }
        cnt+=m[i].second;
      }
  n == n>>1 + (n+1)>>1
  if you have something that is 80%, just check if the thing fraction times 5 is less than total
  Determine overlapping segments: sort segments (pairs) by end points and by start points. if the results differ: invalid (crossing segments).
  When you have three elements: int add = boxes[(j + 1)%3][i] + boxes[(j + 2)%3][i];
  2^20 is about a million (10^6), 2^30 about a billion (10^9), and 2^10 about a thousand (10^3)
  longest common substring can be found in O(nm) using DP.
  pattern matching in time O(m+n) with KMP (first or number of occurrences of a substring)
  circles intersecting: look at distance between middles and radius only.
  if you're sorting the characters in a vector of strings: sort items first, then sort strings.
  compile = alt+c, submit = alt+s
  don't do multiple steps in a recursion
  If you need to find where p^q == a given number iterate over all powers of q that fit in a long (59) You can find those with binary search
  With the prime factors algo: the lowest thing to divide it is always a prime. Because if it wasn't, then there was another smaller number that would divide it.
  Any multiplication of a prime cannot be a multiplication of other primes. Prime factor division is unique. (remember prime factorization has different primes to the power, not simply x times a prime)
  For testing whether 3 things are equal, two comparisons are enough, for testing whether all are distinct, you need 3 comparisons.
  lexicographical sorting means return the thing that has the first element compared that is smaller. if the first thing is the same, then compare the next thing.
  integer overflow test: (s*s)/s == s
  When a game of two players and who wins can't make a move: think of parity.
  Rule of thumb: if the problem asks "in how many ways..." (especially if the result is returned modulus something) it is most likely DP. 
  Rule of thumb 2 (probably some other finger?): the complexity is usually the number of cells of the table(dp array), multiplied by the number of operations for each state.
  Secondly, problems with complex state often lead to really massively used approach: maps. With several million states balanced tree maps become really slow.
  When you multiply two numbers 10^12 * 10^12 you get a number 10^24
  2^24*3 = 72 won't fit in long long
  When something % gcd is 0 you can divide by gcd
  if two numbers A and B are prime (or relatively prime: they share no common prime factors in their factorization), their LCM is A*B
  INT_MAX = 2^31 -1
  10^18 fits in a long long
  10^9  fits in an int
  In problems that ask you for the idx-th element of a sorted sequence (where just simulating creating a sorting the sequence would time out), it tends to be productive to turn the problem into a counting problem. Let us say we wish to build the number given by the idx index.
  When you have a solution that needs to be closest to another solution, divide and conquer: approach it from both sides (greatest number smaller than target and smallest number greater than target). That makes a problem that doesn't have a greedy solution into a problem that does have a greedy solution.
  
  
  
COMPOSITIONS OF A NUMBER
  C(n,k) = n!/(k! * (n-k)!)
  2^a = the sum of all the bico(a,i) for 0 <= i <= a
  With lots of combinatorial problems: find the base cases (odd, even, fixed sizes, different types), and then assign just the minimum amount of items to each group, and multiply with the bico(n+k-1,k) that says assign the remaining k items to any of the n groups. Often, there is a choice: even or odd groups, odd groups of type 1 or type 2. For each of these it's just a simple bico(n,k), for ONE of the options. We use the bico(n+k-1,k) only to divide the remaining elements over the groups. 
  2^(n-1) compositions of a number (where all are positive ints), because you can write a number as
  1 1 1 1  (with n ones and n-1 spaces), and between each number you can put either + or comma to obtain a unique composition.
  number of compositions of a number n into exactly k parts is given by C(n-1,k-1). Because we have n-1 boxes (spaces to put a plus sign), and we can only put a plus sign in k-1 of them (so that the result is the sum of k parts) (also remember that they are all treated distinctly because they are the first argument to C).
  bico(n+k-1,k-1) when there are k-1 separators to distribute between a list of n objects == equivalent to the number of ways to split n objects into k groups some of which can be empty. Times k! then it becomes the number of sequences
  Weak compositions: we now have C(n+k-1,k-1), the added k here is because every k-composition of n+k corresponds to a weak one of n by subtracting 1 from each of the k segments.
  The number of distinct sequences 
  http://en.wikipedia.org/wiki/Composition_%28number_theory%29 ways of writing n as the sum of positive ints
  There are C(n+k-1,k) ways to choose k elements from a set of n elements if repetitions are allowed. (Meaning that sets some sets can be empty). C(n+k-1,k) different ways to assign k elements to n sets (of which some can be empty). It is also the number of ways to divide k elements over n sets (some of which might not get any).
  This is not exactly the same as the sum of the number of ways to choose i elements with 1 <= i <= k from a set of n elements. Because when you select 2 elements to belong to the same set, it's like selecting one element less.
  If not only the subset membership but also the order matters: multiply by factorial(n)
  C(n,k) = factorial(n)/(factorial(k)*factorial(n-k)) (see if you can actually use it somewhere)
  Total number of arrangements of a set with n elements (number of permutations if not all permutations have to include all members): a(n) = Sum_{k=0..n} n!/k!. This is bigger than the factorial.
  
  NUMBER OF PARTITIONS OF A SET (Bell Number)
    You can use backtracking to generate all partitions for a number.
    B(n) if all elements must be used (e.g., it has to be a partition),  B(n+1) if not all elements have to be used
    Here we consider neither the order of teh partitions nor the order of elements iwthin each partition. (Otherwise, consult the ordered bell numbers)
    long long bell_number(int n) {
	  vector<long long> b(n+1,0);
	  b[0] = 1;
	  for (int i=1;i<=n;i++)
	    for (int j=0;j<i;j++)
	      b[i] += bico(i-1,j)*b[j];
	  return b[n];
    }
 
  NUMBER of distinct strings of length n consisting of k distinct elements:
    When you have a problem like you have a string of size n consisting of exactly k distinct objects, the problem is actually equivalent to distributing the n indices of the string over k nonempty subsets. times k! means that instead of different sets we are now talking about different strings (where the order matters).
    k! * Stirling2 (Stirling numbers of the second kind)
    LL stirling2timesfac(int n, int k) {
	  if (k < 0 || k > n) return 0;
	  LL r = 0;
	  for (int i=0;i<k;i++)
	    (r+= ((i%2 ? -1LL : 1LL) * bico(k,i) * modPow(k-i,n))%kMod)%=kMod;
	  return r;
    }
    Alternatively: stirling numbers of the second kind are given by:
    S(n, k) = k*S(n-1, k)+S(n-1, k-1), n>0; S(0, k) = 0, k>0; S(0, 0)=1.
    Stirling numbers of second kind =  ways to partition a set of n objects into k non-empty subsets
    The sum of the Stirling numbers of the second kind for k is 0 to n inclusive is the Bell number, the total number of partitions of a set with n members. B(n+1) if not all elements have to be used

DP TUTORIAL
    States rely on lower states and are independent from greater states
    If you have DP in multiple dimensions, you should always go down in one (the same) dimension (possibly multiple steps).
    The dp array should contain the answer. Because that is what should be overlapping/optimal.
  
  BI-DIMENSIONAL DP
    Check the positions that you can get to the current set from the previous set.
    You use FORWARD dp (dp[i+x] = dp[i][j]...) if you calculate e.g. the number of ways, that is you want to consider all the possibilities.
    You use BACKWARD dp (dp[i] = dp[i-1][j]...) if you need to summarize the information, like taking the minimum or maximum of connected cells. Those have to have already been calculated so you can summarize over them.
    If you use backward dp and you don't want to count current results in the current iteration, treat indices in descending order.
    Note that backwards DP also works in case 1.
    SO ALWAYS USE BACKWARDS DP (looks most like recursion).
    Number of ways to get somewhere on a chessboard = dp state with x, y and number of moves to get there. Keep seen state, the seen state is only to check that we don't have doubles in the queue. The queue enforces that all moves are handled in sequence, so that's why when you get to something you know that you've already had all the ways to get there in the same amount of moves.
    BFS can be done with DP, where the outer loop is the number of moves it takes to get somewhere.
    NOTE: Even when you start in the middle of the field, you can still just process the whole board if you know how many times it should run, without requiring extra storage of a queue. You keep a state of that size anyways, so you can also iterate over it in any order. It's like instead of starting with one point, you start with the whole level. Just that all their counts are set to 0 except for one of them. Less space, more time.
    You can do DFS (or anything else that calculates per move) in a dp that starts with dp[2].
  HARDER DP
    When you run through an array and have to consider subsets left and right of the pivot, you will count subsets multiple times. To avoid this, make sure that the pivot is part of one of the two sets (e.g., of the left set). That way, the left sets you consider are always new (since they contain an element that was not possible before).
    In order for this to work you need to create waysbelow and waysabove arrays, that do not include the value and then for every pivot manually add it to the left set: r+= waysbelow[p][k-values[b]] * waysabove[p][k] (if you construct waysabove on the reverse values array then it is actually waysabove[n-1-p][k].
    If you can have equal elements that can be exchanged then all of them need to be in the sets and we multiply by bico.
    For a combination to be different, only one side needs to be different.
    For DP state, consider which thing should decrease (which signifies the base case), that should be the outer loop, so that in the inner loop you already have those solutions. Typically in 2D DP, outer dimension is the size (1 <= n), inner dimension is the starting point (0 <= n-size). Where for size 0 the cost is 0.
    Make sure that the inner loop is always executed (check edge conditions). Sometimes this means that you have to use <=.
    Sometimes when stuff has to be a certain color, you have to make sure that you include a value for an initial unspecified color that is different from all the others.
    Identify base cases.
    The goal of the different DP steps should be to allow for distinct paths. So never change more than one of the indices in a step. You can't do multiple steps in a path if the state indices can overlap.
    If we have a DP state that includes multiple variables ranging over an index, even when the variable combinations themselves never overlap, the dp states will. You have to handle them separately.
    If values can only be counted once, and your DP state contains multiple sequential indices into the same row, then you have to handle all those cases separately in such a way that values can never be included more than once. (Not just with 3 variables, also with 2 there can be overlap)
    Only preset values in the state for values you skip in your DP loops, or if you don't overwrite them at least.
    When DP with a tree: make the tree such that you can traverse it easily (basically, make it onedirectional instead of bidirectional). Distinct subtrees: give a parameter in the recursion that is 1 if you want to include that subset and 0 if you don't. Once the parameter has been set to 1 you include all of that tree, you can't change it to 0 again. 
    The order has to be done by depth or breadth first search, it cannot be done just by only choosing j > i. Because for DP the order of nested subtrees must follow the order of the indices in the array.
    We move down in an index to explicitly not take the just calculated value into account for (int i=0;i<M;i++), for (int j=M;j>=1;j--) for (int k=i;k<K;k++) dp[j][k]=(dp[j][k] + dp[j-1][k-i])%kMod; when i and j range over the same index (number of ways to sum up to k using each index only once). Note that the limit here is M and not 51. You have to let it run only for the specified values.
  PETR DP
    If you come up with a dynamic programming solution that has too many states, it might well be that most states are unreachable and/or some states can be joined into one since they are handled in the same way anyway. However, as always with dynamic programming, there's no general way to come up with this reduction in size.
    Say you have chosen the subsets for the first K things in the thing. So DP state is is it possible up to index K we chose B to be in a set having value C.
  PES DP
    Used when not all states might be used:
    for (int i=0;i<(1<<N);i++) {
      for (int j=0;j<N;i++) {
        if (dp[i][j] == -1 or if !dp[i][j]) continue;
        for (int k=0;k<N;k++) {
          if (i&(1<<k) continue;
          dp[k][i|(1<<k)] += dp[j][i]; // used to express "hey we added this last", for capturing all permutations
        }
      }
    }

GCD/LCM -- 06-02-2015
  The MOD can only be 0 when the second number is <= the first number. So in the GCD function, make sure you give the second argument to the mod as parameter.
  The LCM of two numbers must always be a multiple of their GCD. Use this for input checking (GCDLCMEasy.cpp).
  lcm(7,11)/11 (== 7 == 7/gcd(7,11)) is how many events it takes until we start seeing an event on the same day (cycle length) if it is held every 11 days. Note that as soon as we have an event on the same day, the cycle resets since the conditions are now the same as when we started. lcm(7,11)/11 is equal to the number of weekdays if the number of weekdays and the eventdays are relatively prime, meaning that we will see events on all days before seeing it on the same day again. Otherwise, if they are not relatively prime, we will start seeing cycles (with the cycle length being lcm(7,11)/11), but the cycles are the same, i.e., an event is always on the same couple of days. The exact days depend on the offset of what weekday you start on. If you start counting days from 0, all possible days are all multiples of the gcd (mod the value itself (in this case 7)) (unless one divides the other).
  The number of points with integer coordinates that lie on a line between two points separated by height a and width b is gcd(a,b)-1
  (3^2*2^3)^2 = (3^4*2*6) -> If you square, you multiply the exponents of by 2.
  Any number A+B you can write as g*(A/g + B/g) where g=gcd(A,B). So any number equal to m*A+n*B also has to be divisible by the gcd of A and B.
  If A is divisible by x, then A%x == 0.
  If A is divisible by x, then A + A is divisible by x, i.e., (A+A)%x == 0.
  If A is divisible by x, then n*A is divisible by x, i.e., (n*A)%x == 0.
  So n*A+m*B is divisible by gcd(A,B). Because this gcd occurs as a factor in both parts, so it can be divided out.
  A necessary condition for X^i to be a multiple of Q is that X must be a multiple of all prime factors of Q (note: all powers!).
  The minimum common multiple of all the prime factors of Q is their product.
  So we will factorize Q and find that its factorization is: p1^4 * p2^2 * p3^8. Then Y= (p1 * p2 * p3) is the minimum common multiple of the prime factors of Q.
  Number of multiples of Y between A and B, where Y is a multiplication of primes: simply B/Y - (A-1)/Y. This is the number of times that Y fits in between A and B.
  The first number that leaves a remainder of n-1 for every n up to a certain max is the lcm(of all those numbers)-1.

  Greatest common divisor: 
    int gcd(int a,int b) {
	  if (b == 0) return a;
	  return gcd(b,a%b);
    }
  Least common multiple:
    int lcm(int a,int b) {
	  int g = gcd(a,b);
	  return (a/g)*b;
    }
    (NOT VERY EFFICIENT FOR large vector of stuff)
 
 DIV/MOD -- 06-02-2015
   sign of second argument to mod doesn't matter
   mod is negative if first term is negative
   Negative modulo is just positive modulo with a minus in front
   a%b with abs(a) < abs(b) is always a
   a/b with abs(a) < abs(b) is always 0
   !!! IF a MOD n = 0 then a*b MOD n == 0 FOR ANY b
       (if b is a divisor of a then b is also a divisor of c*a)
   !!! IF a MOD n = 0 then a+b MOD n == b MOD n
   if A mod B == 0 then B is a divisor of A, and then gcd(a,b) == b
   Divisor means n*A = B, it does not mean: A^n = B (that requires matching all prime factors and their powers)
   Both divisor and the square root thing will leave mod 0.
   if we have 1 solution mod A we also have 1 solution mod B
   So all divisors of A have just one solution too because they fit equally in A without shifting.
   So when we have a number that is X times a divisor, it has X solutions (unless itself is a divisor)
   Congruence relations: a = b (mod n) means the difference between a and b is a multiple of n
   a1+a2 = b1+b2 (mod n)
   a1-a2 = b1-b2 (mod n)
   a1a2 = b1b2 (mod n) // only for integers
   if you have a%4 != 0 and b+c == a and b%4 == a%4 then c%4 == 0
   When it is known that (a-b)%divisor == 0, then all we really know is a%divisor == b%divisor, but they are not necessarily 0!

PRIME TUTORIAL -- 29-05-2015
  composite means not a prime
  1 is not considered a prime number
  divisors of a number go in pairs. 32 has (1,32), (2,16) and (4,8)
  Every number has an even number of (distinct) divisors unless it is a perfect square, because then (sqrt(),sqrt()) forms just one pair.
  p1^x*p2^y*p3^z*... +1 where x,y,z >= 1 for all prime numbers gives a new prime number. because the number -1 was divisible by each prime, so it must add at least the lowest prime (2 or more) to be divisible by it again.
  Two numbers being coprime means they don't share any divisors other than 1 (i.e., their gcd is 1).
  Another word for coprime is relative prime.
  A number is not coprime with itself: co prime means the GCD is 1. gcd(p,p) == p.
  p and (p-1) are coprime for any integer p>1. because any prime factor that divides (p-1) must add at least itself before it can divide a number again. the lowest prime factor is 2. so p itself is coprime.
  For any integer a, (a,a+1) and (a,a-1) are pairs of coprimes
  The product of a series of numbers + 1 is not divisible by any of those numbers.
  Euclid's Theorem: multiply all known prime numbers and add 1 to obtain a new prime number p. Because all prime numbers divide p-1, none divide p.
  All Fermat numbers are coprime (2^(2^n) +1)
  Dirichlet's Theorem: For any two positive coprime integers a and b there are infinitely many primes of the form a + n*b, where n > 0.
  Dirichlet's theorem on arithmetic progressions: a+n*b can be a prime (the sequence contains infinitely many primes, but not all are prime) if a and b are coprime and n > 0.
  Goldbach's Conjecture: For any integer n, n>=4 there exist (at least) two prime numbers p1 and p2 such that p1 + p2 = n. Calculate number of different sums by using the generate primes function and then iterating (linear time, check if i is prime and check if n-i is prime).
  Euler's totient function: phi(n) is the number of positive integers not greater than n and relatively prime with n.
    - If p is prime then phi(p) is p-1 (it doesn't include p itself) and phi(p^a) = p^a - p^(a-1) for any a
    - If m and n are coprime then phi(m*n) = phi(m)*phi(n)
    - if n = p1^a1 * p2^a2 * ... * pk^ak then phi(n) = n* (1-1/p1) * (1-1/p2) * (1-1/pk)
        phi(616) = 616 * (1 - 1/2) * (1 - 1/7) * (1 - 1/11) = 616 * 1/2 * 6/7 * 10/11 = 240. (616 = 2^3 * 7 * 11)
        // EULER"S TOTIENT FUNCTION (FI):
        int fi(int n) { 
	       int result = n; 
	       for(int i=2;i*i <= n;i++) { 
	         if (n % i == 0) result -= result / i; 
	         while (n % i == 0) n /= i; 
	       } 
	       if (n > 1) result -= result / n;
	       return result;
        }
     res(1) = 1,
     res(i + 1) = res(i) + 2 * fi(i + 1), i > 1
   Euler's totient theorem: If n is a positive integer and a is coprime to n, then a ^(fi(n)) === 1 (mod n) (meaning the difference between 1 and a^... is a multiple of n (= congruence relation, triple equal sign).)
   Euler's totient theorem: for any two integers a and b that are coprime and b is prime, a^b % b = a % b  ->  a^(b-1) % b == 1 % b  ->  a^(b-2) % b = 1/a % b (this is used in modular inverse)
   if b is prime and a < b, then a and b are coprime.
   Fermat's little theorem:
     a and b coprime, b is prime: a^(b-1) % b == 1 % b
     a and b coprime, b is prime: a^b % b == a % b
     NOTHING HOLDS IF P IS NOT PRIME (same with euler)
   Fermat's little theorem: If p is a prime number, then for any integer a that is coprime to p, we have a^p === a (mod p) or: a^(p-1) === 1 (mod p). Fermat's little theorem is a special case of Euler's totient theorem when n is prime (because when n is prime, fi(n) is n-1). Example, when a = 4 and p = 3, a^p = 64, so 64-a = 64-4 = 60  and 60%3 == 0.
   Modular multiplicative inverse: if a and m are coprime, then a^fi(m) = 1 (mod m) -> a^(fi(m)-1) = a^(-1). if (m is prime then fi(m) is m-1. So modular multiplicative inverse of a is a^(m-2) mod m.
   When written as a prime factorization, the number of divisors of a number is the multiplication of (the exponents+1) (because each exponent can also be 0 and because 1 counts as a divisor). Any subset of those prime exponents is a divisor of the orig. number.
   So a prime factor just adds divisors.
   If GCD(a,b) is a, with a <= b, then a is a divisor of b. This is always the case for the prime factorization subsets.
   if GCD(a,b) != 1 and not a or b, then they share a divisor but one is not a divisor of the other.
   GCD(a,b) == 1 for numbers b relatively prime to a. If you just want the amount of such numbers (between 1 and a-1), use fi(a) (Euler's totient).
   GCD(a,b) == b when b <= a (equivalent to  a%b == 0) when b is a divisor of a. If you just want the amount of such numbers (the number of divisors of a), use the prime factorization (and multiply (the exponents+1)).
   
                  32        <=    131
                  64        <=    311
   THERE ARE     500 primes <=   3571
   THERE ARE  ~1.000 primes <=   7919
   THERE ARE ~10.000 primes <= 104729
   
  ERATOSTHENES SIEVE : GETPRIMES GET PRIMES <= SQRT(N)
  vector<int> primes(int n) {
    vector<bool> prime(n+1,true);
    for (int i=2;i*i<=n;i++)
      if (prime[i])
        for (int j=i*i;j<=n;j+=i)
          prime[j] = false;
    vector<int> r;
    for (int i=2;i<prime.size();i++)
      if (prime[i]) r.push_back(i);
    return r;
  }
  
  GET PRIMES <= N
  vector<int> primes(int n) {
    vector<int> prime;
    for (int i=2;i<=n;i++) { // NOT i*i
      bool ok = true;
      for (int j=0;j<prime.size();j++)
        if (i%prime[j] == 0) {
          ok = false;
          break;
        }
      if (ok) prime.push_back(i);
    }
    return prime;
  }
  
  PRIME FACTORS BY TRIAL DIVISION
  vector<int> prime_factors(long long n) {
    vector<int> r;
    for (int i=2;i*i<=n;i++) {
      while (n%i == 0) {
        r.push_back(i);
        n/=i;
      }
    }
    if (n > 1) r.push_back(n);
    return r;
  }
  
  WHEN YOU JUST WANT THE DIVISORS
  vector<int> getdivisors(int n) {
    vector<int> r;
    for (int i=1;i*i<=n;i++) {
      if (n%i == 0) {
        r.push_back(i);
        if (n/i != i)
          r.push_back(n/i);
      }
    }
    sort(r.begin(),r.end());
    return r;
  }

BIPARTITE GRAPHS MBPM
  A bipartite graph is a graph whose vertices can be divided into two disjoint sets, such that every edge in the graph connects a vertex in U to one in V.
  You can test for bipartiteness in a graph in linear time by performing depth first searches on all unseen components. If they find a neighboring node that is already seen, and it has the same color as the current node (to which it is connected), then bipartiteness is not possible.
  mbpm (maximum number of connecting edges, no two of which share an endpoint) is equivalent to minimum vertex cover for bipartite graph (== set of vertices such that for every edge in the graph at least one vertex is in the set, and then the minimum set of that) (= minimum number of vertices to remove to separate the two graphs (i.e., that is assuming that you remove them optimally, which is that you remove all from one side).
  If it says that "all items in this set are not compatible with themselves", you have yourself a bipartite graph.
  Determining all connected components? use Disjoint Set Forests (much faster than dfs times number of components).
  MBPM algorithm doesn't work with edge weights. And the Maxflow algorithm doesn't work when you want to leave one edge per node. In this case, ya gotta brute force it.
  If you need to determine whether a node is always included in all valid combinations and you know all valid combinations have a fixed size, then remove those edges from the graph and see if the mbpm still has the same size (i.e., includes all nodes).
  Use mbpm matching divided by 2 if you just want the max number of pairs that satisfy a condition (and don't care about direction). But then there's also easier ways to calc that.
  
  MAXIMUM BIPARTITE MATCHING MBPM MAXFLOW : Complexity: O(E*V) is about O(n^3 or n^2.6) with n = max(nl,nr)
    When this is too slow, you can simulate it with a MaxFlow network, with edges from source to all nl nodes with weight 1, edges from nr nodes to sink with weight 1, and edges from nl to nr with weight INF. This has a lot lower complexity (O(
    Both Maxflow and MBPM are O(V*E), but MBPM implementation has O(V^3) (where V = max(nl,nr)), while Maxflow is actually O(V*E), so Maxflow is an order faster when each node has a small constant number of edges (i.e., in 4-connectivity).
    MBPM is too slow when V > 500.
    
  bool bpm(int l,vector<int>& leftof,vector<bool>& seenl, vector<bool>& seenr) {
    if (seenl[l]) return false;
    seenl[l] = true;
    for (int r=0;r<nr;r++) {
      if (seenr[r] || !g[l][r]) continue;
      seenr[r] = true;
      if (leftof[r] == -1 || bpm(leftof[r],leftof,seenl,seenr)) {
        leftof[r] = l;
        return true;
      }
    }
    return false;
  }
  int calc() {
    vector<int> leftof(nr,-1);
    int r = 0;
    for (int l=0;l<nl;l++) {
      vector<bool> seenl(nl,0);
      vector<bool> seenr(nr,0);
      r+= bpm(l,leftof,seenl,seenr);
    }
    return r;
  }


MAX FLOW MIN CUT
  Same calculation, two results: one is max flow, one is min cost. The cost is if you use that edge in the final network, it costs you the cost. The cost of an edge that already exists is 0, the costs of a new edge is 1 (or something). It is the cost to use the edge in the final configuration. Max flow is the maximum flow capacity that goes from source to sink. Min cost-max flow problem is the problem to find a flow that is maximum but has the lowest cost among the maximums.
  This idea - adding appropriate infinite edges to the network to make sure each finite cut possesses the properties we require - actually comes up pretty often in algorithmic matches.
  Max flow = min cut = minimum cost to cut the network in two. This is equal to the sum of the weights of the edges removed in the min cut. It is equal to the flow that was going from one side of the graph to the other. It is calculated by finding a path from source to sink, finding the minimum flow in that path, removing that minimum flow from all edges in that path and adding it to the result.
  For min cut/max flow problem, the arrows go in reasoning starting from false. If something is false then we know something else is false as well. if d[i] <= 1 is false and i is linked to j, then we know d[j] <= 0 is false. When the edge is removed,  the cost should be the cost of the end node being true (0 to always force a break, INF to make sure edges are not removed). If you know the value of a node in advance, set the cost of that edge to 0, so it is removed, and the cost of all other edges on its path to INF so they are never removed (because they connect to true and all of them always have to be true).
  Mincuts can be used to separate source (false) from sink (truth) in a graph, where you have consecutive edges being the value of that thing having that value (i.e., if you remove that edge the truth value is on the right), with nodes dist[i] <= x for 0 <= x <= n-1. If you know initial nodes are connected to each other, they are within a certain distance of each other, and so you add additional edges with infinite cost to remove.
  The mincut (is equal to maxflow) problem is where you have a graph with a source and a sink that need to be separated, and each edge has a certain cost for removal. The min cut is the minimum sum of the cost of the edges you remove to separate source from sink. Actually, source and sink is not part of definition of a cut: it just requires at least two connected nodes to be on one side.
  MBPM algorithm doesn't work with edge weights. And the Maxflow algorithm doesn't work when you want to leave one edge per node. In this case, ya gotta brute force it.
  // find a path from source to sink with positive flow
  // of the edges on the path, find the one with minimum flow
  // subtract this minimum from all edges in the path,
  // so at least one edge cannot be used anymore
  // then return that minimum flow or 0 if no path found
  // the sum of all the minimum flows that are required to make the path
  // work is the max flow and thus the min cut
  // as long as there is a path from source to sink,
  // cut the edge with minimum flow
  // for the new template: it adds every time the flow increment also the cost increment


// size is number of nodes excluding src/dest (so typically n+m)

struct Network {
  static const int maxn = 1e5+5;
  static const int maxm = 1e5+5;
  static const int oo = 1e9;
  static const int inf = 1e6;
  int node, nedge, src, dest;
  int head[maxn], point[maxm], next[maxm], flow[maxm], capa[maxm], cost[maxm];
  int dist[maxn], expand[maxn], prev[maxn], edge[maxn];
  bool changed[maxn];
  Network(int size) {
    node = size+2;
    src = size;
    dest = size+1;
    nedge = 0;
    for (int i=0;i<node;i++) head[i] = -1;
  }
  void addEdge(int u, int v, int c, int w = 0) {
    point[nedge] = v;
    capa[nedge] = c;
    cost[nedge] = +w;
    flow[nedge] = 0;
    next[nedge] = head[u];
    head[u] = (nedge++);
    point[nedge] = u;
    capa[nedge] = 0;
    cost[nedge] = -w;
    flow[nedge] = 0;
    next[nedge] = head[v];
    head[v] = (nedge++);
  }
  void minCostMaxFlow(int &mcost, int &mflow) {
    mflow = mcost = 0;
    while (1) {
      for (int i = 0; i < node; i++) {
        dist[i] = oo;
        prev[i] = -1;
        changed[i] = false;
      }
      dist[src] = 0;
      changed[src] = true;
      expand[src] = oo;
      while (1) {
        bool ok = true;
        for (int i = 0; i < node; i++)
          if (changed[i]) {
            changed[i] = false;
            for (int k = head[i]; k >= 0; k = next[k])
              if (flow[k] < capa[k] && dist[i] + cost[k] < dist[point[k]]) {
                dist[point[k]] = dist[i] + cost[k];
                changed[point[k]] = true;
                prev[point[k]] = i;
                edge[point[k]] = k;
                expand[point[k]] = min(expand[i], capa[k] - flow[k]);
                ok = false;
              }
          }
        if (ok) break;
      }
      if (prev[dest] < 0) break;
      int d = expand[dest];
      mflow += d;
      mcost += d * dist[dest];
      for (int k = dest; k != src; k = prev[k]) {
        flow[edge[k]] += d;
        flow[edge[k]^1] -= d;
      }
    }
  }
};

PROBABILITIES TUTORIAL
  Outcome: result of an experiment or other situation involving uncertainty. One point in the sample space.
  Sample space: set of all possible outcomes of a probability experiment.
  Event: any collection of outcomes of an experiment. Single (has one outcome) and compound (multiple outcomes) events.
  Probability of an event is simplly the number of favorable outcomes divided by the total number of outcomes.
  If you are calculating all possible pairs quadratically, then you can just start j at i+1 (or i, depending on whether the event i == j should be included).
  P(all events) = P(E1) * P(E2) * P(E3)   if they are all independent events.
  P(at least one) = 1-P(E1')*P(E2')*P(E3') = 1-(1-P(E1))*(1-P(E2))*(1-P(E3))
  See which one is easier to solve. The actual problem or the complementary problem.
  If something can repeat the same values, the number of outcomes doesn't change: for (int i = 1;i<n;i++) r*= double(ids-i)/ids; If something cannot repeat the same values:
    for (int i=0;i<assignments.size();i++) {
      for (int j=0;j<assignments[i];j++)
        r*= double(ids-sumass-j)/(ids-j); // ids get smaller because less stuff accepted.
      sumass += assignments[i];   // numerator and denominator decrease by the same amount but you still need
    }                             // to count them individually.
   To be sure that we have at least one thing chosen twice, we need n+1 values, NOT n values.
   You don't need to pass probabilities along in a state. Just multiply the result of rec by 1/N if you have N rec calls in that function. You can use DP because the result scales with the probabilities.
   Sometimes you can't just count all good cases and all bad cases because it can stop early in some branches and then the total count is off. Then you need to use conditional probabilities.
   If the bounds of your next jump depend somehow on your previous jump, then you will have to use a recursive function with a state. If they don't, you can use a big array of all outcomes and iterate over it as many times as there are throws (start with probability 1 in the first cell).
   A recursive function should always return conditional probabilities: given the current score, what is the probability that we win. So at the end the probability should either be 1 or 0.
   Monte Carlo algorithms: may sometimes produce an incorrect solution. We bound hte probability of failure.
   Las Vegas algorithms: always give the correct solution, the only variation is the running time, we study the distribution of the running time.

GEOMETRY PROBLEMS
  sin, tan, cos return the angle in radians. To convert to degrees, use: tan(a)*PI/180.
  When lines divide a plane, each line adds as many new sections as 1+the number of unique intersections with previous lines
  When all polygon points are integer coordinates, and their perimeter is integer then their perimeter cannot be odd. When their perimeter is even, it can always be accomplished with a polygon of 4 sides (assuming perimeter >= 4). And sometimes also with 3 sides (e.g., 3^2 + 4^2 = 5^2).
  Pythagorean theorem only works for triangles of which one angle is 90 degrees (called a right angle).
  You can construct any triangle (even those without straight angle, by considering all possible combinations of two straight angled triangles. (imagining that the hypotenuse points to a point on a circle edge (with possibly different radii), and the a and b lengths are the x- and y-coordinates. then draw a line between those two points to get a triangle with the origin. (note: to also catch the straight angled triangles, you need to include triangles with edge length 0 in there.
  
  Test if point 3 lies between points 1 and 2:
   int z1 = (x3-x1)*(x2-x1) + (y3-y1)*(y2-y1);
   int z2 = (x3-x2)*(x1-x2) + (y3-y2)*(y1-y2);
   if (z1 < 0 || z2 < 0) // point 3 does not lie in between points 1 and 2
  

INTERSECTION POINT OF TWO LINES
  pair<double,double> intersection(double x1s, double y1s, double x1e, double y1e, double x2s, double y2s, double x2e, double y2e) {
    double m = ((y1e-y1s)*x1s+(x1e-x1s)*y2s-(x1e-x1s)*y1s-(y1e-y1s)*x2s)/((y1e-y1s)*(x2e-x2s)-(x1e-x1s)*(y2e-y2s));
    return pair<double,double>(x2s+m*(x2e-x2s),y2s+m*(y2e-y2s));
  }

CROSS PRODUCT TO DETERMINE IF POINT LIES LEFT OF LINE
  bool left_of_line(const PII& p, const PII& from, const PII& to) {
    LL d = ((LL)to.first-from.first)*(p.second -from.second) -
    ((LL)to.second-from.second)*(p.first - from.first);
    return d>=0;
  }

TRIANGLE AREA (points have to be given in counterclockwise order(?)) (vector cross product)
  double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
      x1 -= x3; y1 -= y3; x2 -= x3; y2 -= y3;
      return (x1 * y2 - x2 * y1) / 2;
  }

CONVEX HULL (with expected values):
  double expectation(vector <int> x, vector <int> y, vector <int> prob) {
    int n = x.size();
    double r = 0;
    for (int i=0;i<n;i++) {
      int x1 = x[i];
      int y1 = y[i];
      for (int j=0;j<n;j++) {
        if (j == i) continue;
        int x2 = x[j];
        int y2 = y[j];
        double pr = prob[i]*prob[j]/1000000.0;
        for (int k=0;k<n;k++) {
          if (k == i || k == j) continue;
          int x3 = x[k];
          int y3 = y[k];
          bool bad = false;
          int d = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
          if (d < 0) bad = true; // if x3 lies right of x1->x2
          else if (d == 0) {
            int z1 = (x3-x1)*(x2-x1)+(y3-y1)*(y2-y1);
            int z2 = (x3-x2)*(x1-x2)+(y3-y2)*(y1-y2);
            if (z1 < 0 || z2 < 0) bad = true;
          }
          if (bad)
            pr *= (1000-prob[k])/1000.0;
        }
        r += pr*(x1*y2 - x2*y1);
      }
    }
    return r/2.0;
  }


Dynamic Programming
  There are two key attributes that a problem must have in order for dynamic programming to be applicable: optimal substructure and overlapping subproblems. If a problem can be solved by combining optimal solutions to non-overlapping subproblems, the strategy is called "divide and conquer" instead. This is why mergesort and quicksort are not classified as dynamic programming problems.
  Two versions: (both work for each problem)
  Top-down approach: memoization (store previous solutions)
  Bottom-up approach
  Matrix multiplication: nr of operations depends on the order of multiplication (all give same result). m[i][j] is minimum operations needed to get from matrix i to matrix j.
  function LCSLength(X[1..m], Y[1..n])
      C = array(0..m, 0..n)
      for i := 0..m
         C[i,0] = 0
      for j := 0..n
         C[0,j] = 0
      for i := 1..m
          for j := 1..n
              if X[i] = Y[j]
                  C[i,j] := C[i-1,j-1] + 1
              else
                  C[i,j] := max(C[i,j-1], C[i-1,j])
    return C[m,n]
  DP with profile: when you don't need to retain all information.
    code the profile in an integer (base 3 of length m). can precompute this.
    Arrays of integers act as functions with set and get operations
    current dp[][][] value already correct, adjust the next one
  int nx = ( M - 1 ) ^ x; <-- set of bits not set in x
  for( int px = x; ; px = (px-1)&x ) every time unset 1 bit in px
  p[i] = ( ( i << 1 ) ^ ( i >> 1 ) ) & i; <-- my left and right neighbor differ and i am colored: this gives a parity for the next row
  // Precalculate sum[x][y], sum of coprime pairs:
  //  (p,q) (1 <= p <= x), (1 <= q <= y)
   for (int i = 1; i < A; i++) {
	   for (int j = 1; j < B; j++) {
		   int x = ( (gcd(i,j) == 1) ? 1 : 0 );
		   // Note: how we don't count double here:
		   sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
	   }
 }
 

IN-ORDER DFS

  void dfs(int node, vector<int>& tpath, int rev) {
    // in-order traversal to ensure
    // that connected nodes appear
    // in adjacent indices in the path vector
    bool nya = true;
    if (rev == 0) tpath.push_back(node);
    for (int i=0;i<m;i++)
      if (g[node][i] && marked[i] == -1) {
        marked[i] = marked[node];
        dfs(i,tpath,(rev == -1 ? nya : rev));
        if (nya) {
          if (rev == -1) tpath.push_back(node);
          nya = false;
        }
      }
    if (rev == 1 || (rev == -1 && nya)) tpath.push_back(node);
  }

NEW C++ https://en.wikipedia.org/wiki/C%2B%2B11
 C++11 (formerly known as C++0x)

Google C++ Style
  Don't inline function if > 10 lines long. Don't inline destructors


Integer factorization is not polynomial in the number of bits
gcd (Euler's Algorithm) is polynomial in length of digit in base 10

 Convex hull O(n^floor(d/2))
 max flow

DFS and BFS linear in number of edges, which may be quadratic in number of vertices.
Dijkstra O(|E|+|V|log|V|) with min priority queue.

maximizing or minimizing an objective? -> linear programming (with multiple constraints): simplex
  - write things as formulas mathematically
  - integer linear programming is np hard
  - from min to max -> negate coefficients in the objective function only
  - if no nonnegativity constraint -> add extra variable for each one
  - == instead of <= -> translate to two formulas, one with >= and one with <=
  - turn >= into <= by reverting the signs
  !! read from page 785 onwards

optimization (many possible solutions) -> dynamic programming (using previous solutions)
  - requirements: optimal substructure and overlapping subproblems
  - longest common subsequence (O(min(n,m)) with DP)
  function LCSLength(X[1..m], Y[1..n])
      C = array(0..m, 0..n)
      for i := 0..m
         C[i,0] = 0
      for j := 0..n
         C[0,j] = 0
      for i := 1..m
          for j := 1..n
              if X[i] = Y[j]
                  C[i,j] := C[i-1,j-1] + 1
              else
                  C[i,j] := max(C[i,j-1], C[i-1,j])
    return C[m,n]
 - Longest common substring O(mn) with DP
 function LCSubstr(S[1..m], T[1..n])
     L := array(1..m, 1..n)
     z := 0
     ret := {}
     for i := 1..m
         for j := 1..n
             if S[i] == T[j]
                 if i == 1 or j == 1
                     L[i,j] := 1
                 else
                     L[i,j] := L[i-1,j-1] + 1
                 if L[i,j] > z
                     z := L[i,j]
                     ret := {S[i-z+1..i]}
                 elif L[i,j] == z
                     ret := ret ? {S[i-z+1..i]}
             else L[i,j]=0;
    return ret
    

Bit Shift:
>> arithmetic (or signed) right shift
>>> logical (or unsigned) right shift
<< left shift (both logical and arithmetic)
can be applied to all integer values (int long, possibly short byte char)
in some languages the bitshift will convert result to int
if you store number as bitstring with least significant right, then 
left shift does multiplication by 2
a << b == a * 2 ^b
these shifts are not circular
right shift is division by two
i <<= x;  // i *= pow(2,x); // i = i * (1 << b) // i = (i << b) // is all the same!!
i >>= y;  // i /= 2^y;
one int max can contain const int N = 1 << 16;
newState ^= 1 << i <--- xor assignment (toggle bit)
xor toggles the state of the 1s it has (in the position of the other string), leaves the zeros alone
never do |= or ^= with something that isn't 1 << ... or  1LL << ...

Ruby:
 - the min is postfixed

Java:
 - import java.util.*;
 - class public
 - array size() is .length (without parentheses)
 - String in java does not have size(), only length()
 - Scanner has .nextInt() and .next() (for word) and .nextLine()
 - Scanner requires import java.util.*;
 - int array int[] n=new int[121];
 - for advanced stuff use ArrayList<..>
 - vector push_back is ArrayList add
 - vector [] is ArrayList.get(i) and ArrayList.set(i,val)
 - when comparing Strings use .equals()

Trees:
 - insert, min, max, successor, predecessor take time O(h) in a binary search tree of height h
 - radix tree is one where the values are accumulated by the path you take to get there. Insertion in a radix tree takes O(k) time where k is the length of the word..
 - operations of normal binary tree take O(n) worst time, red-black trees take O(log n) worst case.
 - Red-Black has 1 extra color bit. Root and leaves are black. If a node is red, both its children are black. For each node, all paths from the node to descendant leaves contain the same nubmer of black nodes.
 - Height of RB tree at most 2 log(n+1)
 

http://apps.topcoder.com/wiki/display/tc/Competing+in+a+Rated+Algorithm+Competition


read up on http://community.topcoder.com/tc?module=Static&d1=help&d2=competitionFaq


MATH G-RESEARCH

See https://en.wikipedia.org/wiki/Taylor_series#List_of_Mac
exp(x) or e^x = 1 + x + x^2/2! + x^3/3!
log(1-x) = x = - \Sum...


Bayesian statistics
P(A|B) = P(B|A)*P(A)/P(B) = P(AnB)/P(B)
P(A|B) = P(AnB)/P(B)
P(AnB) = P(B|A)*P(A)
P(AnB) = P(A|B)*P(B)
P(AnB) = P(A)*P(B) if A and B independent events (i.e., P(A|B) = P(A) = knowing B occurred does not make A more or less likely).

P(A|B) will be bigger than P(AnB)

Partial differential equations: Differential equations of multiple functions.

v securities markets 101; There are different types

Hyperbola cuts 2
Parabola cuts one
ellips cuts one and closes
circle cuts one and is parallel to some axis

Complex functions
Bounded function: like tan x. there is an M such that |f(x)| <= realk M for all x.
Holomorphic: differentiable on its domain
Entire function: holomorphic over the whole complex plane
Analytic function: a function locally given by a convergent power series.

1/16 = 0.0625
1/8 = 0.125
2/8 = 0.250
3/8 = 0.375
4/8 = 0.500
5/8 = 0.625
6/8 = 0.750
7/8 = 0.875
8/8 = 1.000

(1-1/N)^N = e^(-1) as N -> infinity

e = (1 + 1/n)^n as n -> infinity
e^(-1) = (1 - 1/n)^n as n -> infinity

Nash equilibrium: all options for each player have the same expected payoff (but not all players have to have the same expected payoff).

Weak law or large numbers: average of a large nubmer of drawings teands to be very close to the mean of the thing.

Expected value
  Expected value does not exist if the series does not converge absolutely.

  The series 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 does not converge.
  The series 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 does converge (to ln 2)
  
  If the probability distribution of a random variable X admits a probability density distribution f(x), then the expected value is E[X] = integral -infty infty x f(x) dx
  
  Expected value for Cauchy distribution is not defined. Because the mean is defined as integral x f(x) and the integral on both sides is infinite.

P(X = a) == 1 -> Var(X) = 0
Var(X+a) = Var(X)
Var(aX) = a^2Var(X)
Var(aX + bY) = a^2Var(X) + b^2Var(Y) + 2ab Cov(X,Y)
Cov(X,Y) = p* sigma_x * sigma_y (p = correlation)
Var(X) = E[X^2] - (E[X])^2


distribution = cdf
probability = or density = pdf

Minimum means second derivative > 0

Tests for convergence:

  The Ratio Test (series with positive terms only): lim n->infty a_{n+1}/a_n  if <1 converges, >1 diverges, 1 = fails
  The Root Test (series with positive terms only): lim nth root a_n  <1 converges, >1 diverges, 1 = fails
  Raabe's Test (series with positive terms only): lim n->infty n(1-(a_{n+1}/a_n) >1 converges, < 1 diverges, = 1 fails
  Integral Test (series with positive terms only): integral of the thing as a function from 1 to infty either converges or diverges just like the original function. if the function is decreasing and continuous.
  Comparison Test: compare with another function that you know converges., then it converges if all terms <=.
  If terms keep changing sign: absolute convergence implies convergence. So you can just take the abs and see if that converges.
  Gauss' Test (series with positive terms only): a_{n+1}/a_n = 1 - L/n + b_n/n^2 

1 + 2 + 3 + 4 + 5 + n = n(n+1)/2
1 + 4 + 9 + 16 + 25 + n^2 = n(n+1)(2n+1)/6
1 + 8 + 27 + 64 + 125 + n^3 = n^2(n+1)^2/4
Sum of the first n odd numbers is n^2
Sum of the odd numbers <= n is ((n+1)/2)*((n+1)/2); (parentheses are important here)


EXPECTATIONS:
  E[X] = Integral -inf to inf x * f(x) where f(x) is probability density distribution of X
  E[X] = Integral x = 0 to infty P(X >= x) dx = integral x * f(x) dx where f(x) is dentsity --- if X only takes nonnegative values:
  E[X] = E[E[X|Y]]
       = E[X|Y=y] * P(Y=y)
       = x*P(X=x|Y=y)*P(Y=y)
       = x*P(Y=y|X=x)*P(X=x)
  Sum_x Sum_y P(Y=y|X=x) == 1

STATISTICS
  Probability of in 3 rolls rolling a max of 4 is probability of in 3 rolls rolling 4 or higher - prob of in 3 rolls rolling 5 or higher. Because it's easier to work with ranges than with individual events. Because we don't actually know the exact event or in which roll it is taking place. We only know boundaries that can apply to all rolls so that we can multiply them.
 
LOGIC
  Propositional logic: simple: "A man is strong"
  Predicate logic: Uses predicates such as "for all" and "there exists". Includes first order logic, second order logic, and higher order logic.
  Modal logic: extends propositional and predicate logic with modality: <> possibly, [] necessarily.
  Temporal logic:
    binary operators: xUy (until), xRy (release)
    unary operators: N (O) next, F (<>) eventually has to hold somewhere in future, G ([]) globally on the entire subsequent path, A (for all), E (exists).
