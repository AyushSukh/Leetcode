select user_id , 
    concat(UPPER(LEFT(name,1)), lower(Right(name , length(name) - 1 ))) as name
From Users
ORDER BY user_id
