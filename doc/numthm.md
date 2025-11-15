Elementary Number Theory
========================

Author: ZrLnY

Chapter 1. Divisibility
-----------------------

**Thm 1.** if $a,b \in\mathbb{Z}$ and $b>0$, then $\exists$ unique pair $(q,r)$
s.t. $$a=qb+r\quad 0\leq r<b$$

(page 1, [Elementary number theory](textbooks/numthms.pdf))

Then we define, $q$ the quotient, $r$ the remainder. When $b$ divides $a$, we denote $b\mid a$. (other def: not divide $\nmid$, factor, multiple, etc.)

**Some Props**  
1. if $a\mid b$ and $b\mid c$, then $a\mid c$
2. if $a\mid b$ and $c\mid d$, then $ac\mid bd$
3. if $m\neq 0$, then $a\mid b$ iff $ma\mid mb$
4. if $d\mid a$ and $a\neq 0$, then $|d|\leq |a|$

(page 4, [Elementary number theory](textbooks/numthms.pdf))

**Thm 2.** 
1. if $c$ divides $a_1,...,a_n$, then $c$ divides $a_1u_1+...+a_nu_n$ for all $u_1,u_n\in\mathbb{Z}$
2. $a\mid b$ and $b\mid a$ iff $b=\pm a$

(page 4, [Elementary number theory](textbooks/numthms.pdf))

Define $d=gcd(a,b)$ as  
1. $d\mid a$ and $d\mid b$
2. if $c\mid a$ and $c\mid b$, then $c\leq d$

**Lemma 3.** if $a=qb+r$, then $gcd(a,b)=gcd(b,r)$

(page 5, [Elementary number theory](textbooks/numthms.pdf))

**Thm 4.**