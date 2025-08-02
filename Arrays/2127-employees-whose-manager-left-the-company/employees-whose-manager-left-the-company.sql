select employee_id
    from Employees 
    where salary < 30000
    AND manager_id NOT IN (
      SELECT employee_id
      FROM employees
  )
order by employee_id ;
