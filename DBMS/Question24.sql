use sampp;
select ename, job, sal,grade, dname from emp,dept,salgrade
 where job!='clerk' and emp.deptno=dept.deptno and (sal between losal and hisal )
 order by sal desc;