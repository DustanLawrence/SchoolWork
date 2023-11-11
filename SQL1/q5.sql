# Display the first name, last name and rounded years worked of all employees sorted in a desceding order based on the rounded years
SELECT first_name, last_name, ROUND(DATEDIFF(CURDATE(), hire_date) / 365.25) AS rounded_years_worked FROM employees ORDER BY rounded_years_worked DESC;


