use sampp;
DECLARE
@total_wages int
@sal_count int
@comm_count int
@wages int
@salary int
@commission int
DECLARE db_cursor CURSOR FOR
select sal,isnull(comm,0),sal+isnull(comm,0)"wages" from emp where deptno=20;
OPEN db_cursor  
FETCH NEXT FROM db_cursor INTO @salary,@commission,@wages
WHILE @@FETCH_STATUS = 0  
BEGIN  
if(@salary>2000)
set @sal_count=@sal_count+1;
if(@commission>@salary)
set @comm_count=@comm_count+1;
set @total_wages=@total_wages+@wages;

END  
CLOSE db_cursor  
DEALLOCATE db_cursor 


