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

