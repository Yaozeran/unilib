Elementary Number Theory Note
=============================

Author: Yao Zeran

Chapter 1. Divisibility
-----------------------

**Thm 1.** if $a,b \in\mathbb{Z}$ and $b>0$, then $\exists$ unique pair $(q,r)$
s.t.

$$a=qb+r\quad 0\leq r<b $$

(page 1, [Elementary number theory](textbooks/numthms.pdf))

Then we define, $q$ the quotient, $r$ the remainder. When $b$ divides $a$, we denote $b\mid a$. (other def: not divide $\nmid$, factor, multiple, etc.)

**Coro 2.** with above, $b\neq0$ then 

$$a=qb+r\quad 0\leq r<|b|$$

when $b<0$  

$$\frac{a}{b}=q+\frac{r}{b}\quad 0\geq\frac{r}{b}>1\quad q=\lceil a/b\rceil$$

**Some Props**  
1. if $a\mid b$ and $b\mid c$, then $a\mid c$
2. if $a\mid b$ and $c\mid d$, then $ac\mid bd$
3. if $m\neq 0$, then $a\mid b$ iff $ma\mid mb$
4. if $d\mid a$ and $a\neq 0$, then $|d|\leq |a|$

**Thm 3.** 
1. if $c$ divides $a_1,...,a_n$, then $c$ divides $a_1u_1+...+a_nu_n$ for all $u_1,u_n\in\mathbb{Z}$
2. $a\mid b$ and $b\mid a$ iff $b=\pm a$.

(page 4, [Elementary number theory](textbooks/numthms.pdf))

Define $d=gcd(a,b)$ as  
1. $d\mid a$ and $d\mid b$
2. if $c\mid a$ and $c\mid b$, then $c\leq d$

**Coro 4.** if $c\mid a$ and $c\mid b$, then

$$\forall u,v\in\mathbb{Z}.\quad c\mid ua+vb$$

**Lemma 5.** if $a=qb+r$, then $gcd(a,b)=gcd(b,r)$  

(page 5, [Elementary number theory](textbooks/numthms.pdf))

**Thm 6. (Euclid division algorithm)** let $d=gcd(a,b)$, note

$$gcd(a,b)=gcd(-a,b)$$

and assume $a>b$ then  

$$a=q_1b+r_1$$

repeat and use lemma 4, we have  

$$b=q_2r_1+r_2\quad r_1=q_3r_2+r_3$$

finally

$$r_{n-3}=q_{n-1}r_{n-2}+r_{n-1}\quad r_{n-2}=q_nr_{n-1}+r_n\quad r_n=0$$

now $d=r_{n-1}$ 

(page 6, [Elementary number theory](textbooks/numthms.pdf))

**Thm 7. (Bezout's identity)** if $a,b\neq0\in\mathbb{Z}$, then $\exists u,v\in\mathbb{Z}$ s.t.

$$gcd(a,b)=ua+bv$$

then we discuss the set of all these gcd

**Thm 8.** let $a,b\neq0\in\mathbb{Z}$, $d=gcd(a,b)$ then $c\in\mathbb{Z}$ has the form $c=ax+by$ for some $x,y\in\mathbb{Z}$ iff $c$ is a multiple of $d$, and $d$ is the least positive integer of that form.

Define co-prime $a,b$ if $gcd(a,b)=1$, generally, $a_1,...,a_n$ are mutually co-prime if $gcd(a_i,a_j)$ when $i\neq j$.

**Coro 9.** integers $a,b$ are co-prime iff $\exists x,y\in\mathbb{Z}$ s.t. $ax+by=1$.

(page 10, [Elementary number theory](textbooks/numthms.pdf))

**Coro 10.** if $gcd(a,b)=d$ then 

$$\forall m>0.\quad gcd(ma, mb)=md\quad gcd(\frac{a}{d},\frac{b}{d})=1$$

**Coro 11.** $a,b$ co-prime
1. if $a\mid c$ and $b\mid c$, then $ab\mid c$
2. if $a\mid bc$, then $a\mid c$

(page 11, [Elementary number theory](textbooks/numthms.pdf))

Define $l=lcm(a,b)$ if 
1. $a\mid l$ and $b\mid l$
2. if $a\mid c$ and $b\mid c$, then $l\leq c$

**Thm 12.** if $a,b>0\in\mathbb{Z}$, $d=gcd(a,b),l=lcm(a,b)$ then

$$ dl=ab $$

(page 12, [Elementary number theory](textbooks/numthms.pdf))

Linear Diophantine equaions

Chapter 2. Primes
-----------------

Define $p>1\in\mathbb{Z}$ is prime iff only positive divisors are $p$ and $1$.

**Lemma 1.** let $p$ prime, $a,b$ any integers
1. either $p\mid a$ or $p,a$ co-primes
2. if $p\mid ab$, then $p\mid a$ or $p\mid b$

**Coro 2.** if $p$ prime, $p\mid a_1\cdots a_n$, then $p$ divides some $a_i$

**Thm 3. (Fundamental theorem of arithmetic)** each integer $n>1$ has a unique prime-power factorization

$$n=p_1^{e_1}\cdots p_n^{e_n}\quad e_i\in\mathbb{Z}$$

**Lemma 11.** if $2^m+1$ is prime, then $m=2^n$ for some $n\geq0\in\mathbb{Z}$.

(page 30, [Elementary number theory](textbooks/numthms.pdf))

Numbers of form $F_n=2^{2^n}+1$ are called Fermat numbers, those primes are called Fermat primes.

**Lemma 14.** an integer $n>1$ is composite iff it is divisible by some prime $p\leq\sqrt{n}$.

(page 30, [Elementary number theory](textbooks/numthms.pdf))

Chapter 3. Congruence
---------------------

Let $n>0\in\mathbb{Z}$ and $a,b\in\mathbb{Z}$, define $a$ is congruent to $b\mod(n)$ or $a$ is a residue of $b\mod(n)$, written 

$$ a\equiv b\mod(n) $$

if $a,b$ leaves same reminder if divided by $n$, may simply use $a\equiv b$.

**Lemma 1.** for any $n\geq 1$, we have $a\equiv b\mod(n)$ iff $n\mid (a-b)$.

**Lemma 2.** for fixed $n\geq 1$
1. $a\equiv a$
2. if $a\equiv b$, then $b\equiv a$
3. if $a\equiv b$, $b\equiv c$, then $a\equiv c$

(page 39, [Elementary number theory](textbooks/numthms.pdf))

Congruence classes are 

$$[a] = \{b\in\mathbb{Z} \mid a\equiv b\mod(n)\}\quad a\in\mathbb{Z} $$

for given $n\geq 1$; denote set of $n$ equivalent classes $\mod(n)$ by $\mathbb{Z}_n$.

**Lemma 3.** for given $n\geq 1$, if $a'\equiv a$, $b'\equiv b$, then 

$$ a'+b'\equiv a+b\quad a'-b'\equiv a-b\quad a'b'\equiv ab $$

(page 41, [Elementary number theory](textbooks/numthms.pdf))

From this, we see the addition, product, and power are well-defined.

Complete set of residues $\mod{n}$, least non-negative residues, least abs residues, etc.

**Thm 4.** let $n$ have prime-power factorization

$$n=p_1^{e_1}\cdots p_n^{e_n}\quad e_i\in\mathbb{Z}$$

then for any $a,b\in\mathbb{Z}$, we have $a\equiv b\mod(n)$ iff $a\equiv b\mod(p_i^{e_i}) $ for each $i$.

**Lemma 5.** let $f(x)$ be a polynomial, $n\geq1$, if $a\equiv b$ then $f(a)=f(b)\mod(n)$.

(page 44, [Elementary number theory](textbooks/numthms.pdf))

**Thm 6.** there is no non-const polynomial $f(x)$ with integer coefficients s.t. $f(x)$ is prime for all integer $x$.

(page 46, [Elementary number theory](textbooks/numthms.pdf))

**Thm 7.** if $d=gcd(a,b)$, then the linear congruence 

$$ ax\equiv b\mod{n} $$

has a solution iff $d\mid b$; if $d\mid b$, and $x_0$ any solution, then general solution is

$$x=x_0+\frac{nt}{b}\quad t\in\mathbb{Z}$$

the solution form exactly $d$ congruence classes $\mod(n)$.

(page 47, [Elementary number theory](textbooks/numthms.pdf))

**Coro 8.** if $gcd(a,b)=1$, then the solution form a single congruence class $\mod(n)$.

(page 48, [Elementary number theory](textbooks/numthms.pdf))

**Lemma 9.** 
1. let $m\mid a$, $m\mid b$, $m\mid n$, $a'=a/m$, $b'=b/m$, $n'=n/m$, then 

$$ax\equiv b\mod(n) \iff a'x\equiv b'\mod(n)$$

2. let $gcd(a,b)=1$, $m\mid a$, $m\mid b$, $a'=a/m$, $b'=b/m$, then 

$$ax\equiv b\mod(n) \iff a'x\equiv b'\mod(n)$$

(page 49, [Elementary number theory](textbooks/numthms.pdf))

To find general solution when $n$ is large, do
1. find $d=gcd(a,n)$ and see if $d\mid b$, if do, continue
2. replace original with $a'x\equiv b'\mod(n)$
3. use $m=gcd(a',b') to solve $a''x\equiv b''\mod(n)$, if $a''=1$, then $x_0=\pm b$, otherwise continue
4. note we may replace $b''=b''+kn$ to find $gcd(b''',a'')>1$ or multiply both side by $c$

**Thm 10. (Chinese reminder theorem)** let $n_1,...n_k$ positive integers, $gcd(n_i,n_j)=1$ whenever $i\neq j$, $a_1...a_k$ any integers, then solution to simultaneous congruences

$$a_1x\equiv b_1\mod(n_1)\quad ...\quad a_kx\equiv b_n\mod(n_k)$$

form a single congruence class $\mod(n)$, where $n=n_1\cdots n_k$.

Claim that

$$x_0=a_1c_1d_1+\cdots+a_kc_kd_k\quad c_i=n/n_i$$

where $[d_i]$ a single congruence solution class to $c_ix\equiv 1\mod(n)$, satisfies the single congruence.

(page 53, [Elementary number theory](textbooks/numthms.pdf))

**Thm 11.** let $n_i$ mutually co-prime, $n=\Pi n_i$, $f(x)$ polynomial with int coefficients, suppose for each $i$, there are $N_i$ congruence classes $x\in\mathbb{Z}_{n_i}$ s.t. $f(x)\equiv0\mod(n_i)$, then there are $N=N_1\cdots N_k$ classes $x\in\mathbb{Z}_n$ s.t. $f(x)\equiv0\mod(n)$.

(page 58, [Elementary number theory](textbooks/numthms.pdf))

**Thm 12. (General of crt)** $n_i$ are positive ints, $a_i$ any ints

$$a_1x\equiv b_1\mod(n_1)\quad ...\quad a_kx\equiv b_n\mod(n_k)$$

has a solution iff $gcd(n_i,n_j)\mid a_i-a_j$ whenever $i\neq j$; if satisifed, general solution forms a single congruence class $\mod(n)$, where $n=lcm(n1,...,n_k)$.

(page 60, [Elementary number theory](textbooks/numthms.pdf))

Chapter 4. Congruence with Prime Power Mod
------------------------------------------

**Thm 1.** let $p$ be prime, $f(x)=a_dx^d+\cdots+a_1x+a_0$ a poly with int coefficient, $a\not\equiv 0\mod(p)$ for some $i$, then congruence $f(x)\equiv 0\mod(p)$ is satisfied by at most $d$ congruence classes $[x]\in\mathbb{Z}_p$.

(page 66, [Elementary number theory](textbooks/numthms.pdf))

**Coro 2.** if $f(x)=a_dx^d+\cdots+a_1x+x_0$ a poly with in coeff, $p$ a prime, if $f(x)$ has more than $d$ roots in $\mathbb{Z}_p$, then $p$ divides each of its coefficients $a_i$.

**Thm 3. (Fermat's little theorem)** if $p$ a prime, $a\not\equiv 0\mod(p)$, then

$$a^{p-1}=1\mod(p)$$

(page 67, [Elementary number theory](textbooks/numthms.pdf))

**Coro 4.** if $p$ a prime, then $a^p\equiv a\mod(p)$ for every int $a$.

(page 68, [Elementary number theory](textbooks/numthms.pdf))

**Coro 5. (Wilson's theorem)** Int $p$ is a prime iff $(n-1)!\equiv -1\mod(n)$.

(page 70, [Elementary number theory](textbooks/numthms.pdf))

Chapter 5. Euler's Function
---------------------------

A multiplicative inverse for a class $[a]\in\mathbb{Z}_n$ is a class $[b]\in\mathbb{Z}_n$ s.t. $[a][b]=[1]$. A class is a unit if it has multiplicative inverse.

**Lemma 1.** $[a]\in\mathbb{Z}_n$ is a unit iff $gcd(a,n)=1$.

(page 84, [Elementary number theory](textbooks/numthms.pdf))

**Thm 2.** for each int $n\geq1$, the set $U_n$ form a group under multiplicaiton $\mod(n)$ with identity element $[1]$.

(page 85, [Elementary number theory](textbooks/numthms.pdf))

Define $\phi(n)=|U_n|$ the number units in $\mathbb{Z}_n$. Define subset $R$ reduced sets of residues if contains one element from each of $\phi(n)$ congruence classes.

**Thm 3. (Euler's theorem)** if $gcd(a,n)=1$ then 

$$a^{\phi(n)}=1\mod(n)$$

**Thm 4.** if $n=p^e$, $p$ prime, then

$$\phi(n)=p^e-p^{e-1}=p^{e-1}(p-1) = n(1-\frac{1}{p}) $$

**Lemma 5.** if $A$ a complete set of residues $\mod(n)$, and $m,c$ co-prime to $n$, then set $Am+c=\{am+c\mid a\in A\}$ is also a complete set of residues $\mod{n}$.

**Thm 6.** if $m,n$ are co-prime, then $\phi(mn)=\phi(m)\phi(n)$.

**Coro 7.** if $n$ has prime-power factorization $n=p_1^{e_1}\cdots p_k^{e_k}$ then 

$$\phi(n)=\Pi(p_1^{e_i}-p_e^{e_i-1})=\Pi p_i^{e_i-1}(p_i^{e_1}-1)=n\Pi(1-\frac{1}{p_i})$$

**Thm 8.** if $n\geq 1$, then

$$\sum_{d\mid n}\phi(d)=n$$