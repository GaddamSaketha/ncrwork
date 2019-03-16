use sampp;
DECLARE
@wages int
@salary int
@commission int
DECLARE db_cursor CURSOR FOR
select sal,isnull(comm,0),sal+isnull(comm,0)"wages" from emp where deptno=20;
OPEN db_cursor  
FETCH NEXT FROM db_cursor INTO @salary,@commission,@wages
WHILE @@FETCH_STATUS = 0  
BEGIN  



END  
CLOSE db_cursor  
DEALLOCATE db_cursor 


