use sampp;
select ename, sal+isnull(comm,0)"renumeration" from emp;