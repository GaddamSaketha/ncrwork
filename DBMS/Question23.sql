use sampp;
select * from emp where deptno in(select deptno from dept where loc='dallas');