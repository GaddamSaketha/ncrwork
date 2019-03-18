use sampp;
SELECT *
FROM emp e
WHERE hiredate IN
    (SELECT min(hiredate)
     FROM emp
     WHERE e.deptno= deptno )
ORDER BY hiredate;
