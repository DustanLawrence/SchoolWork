import java.sql.*;
import java.time.LocalDate;
import java.io.File;
import java.util.Scanner;


public class main {

private static Connection conn = null;

public static void main(final String[] args) {     
		String creds;
         try {
        	creds = loadDatabaseCreditials();
        	//  Load and register the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            // Establish a connection
            conn = DriverManager.getConnection(creds);

            if (args.length > 1) {
            	switch(args[0]) {
            	case "show":
					switch(args[1]){
						case "employees":
							showEmployeesByDepepartment(args[3]);
						break;
						case "salaries":
            				sumEmployeesSalary();
						break;
					}
            		break;
            	case "add":
            		addEmployees(args[2],args[3],args[4],args[5],args[6],args[7]);
            		break;
            	case "delete":
            		deleteEmployees(Integer.valueOf(args[2]));
            		break;
            	default:
            		System.out.println("Invalid Command");
            	} 	
            }else {
            	System.out.println("No Command Provided.");
            }
            
            // Close the connection
             conn.close();
         } catch (ClassNotFoundException e) {
             System.out.println("MySQL JDBC Driver not found!");
             e.printStackTrace();
         } catch (SQLException e) {
             System.out.println("Connection failed!");
             e.printStackTrace();
         }
    }

	private static String loadDatabaseCreditials() {
		String creds;

		try {final File inputcreds = new File("credentials.txt");
		final Scanner myCreds = new Scanner(inputcreds);
		
		creds = myCreds.nextLine();
		return creds;


		} catch (Exception e) {
			System.err.println(e);
			
		}
		return "DIDN't WORK DUNNO";
		
	}

	private static void sumEmployeesSalary() {
			try {
			final PreparedStatement stmt = conn.prepareStatement("Select Sum(salary)as Sum from salaries where to_date = \"9999-01-01\";");
			final ResultSet resSet = stmt.executeQuery();
			while (resSet.next()){
                	 	final long empNo = resSet.getLong("Sum"); 
                	 	System.out.printf("%-25d\n", empNo);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}



	private static void deleteEmployees(final int empno) {
			try {
			final PreparedStatement stmt = conn.prepareStatement("select first_name, last_name from employees where emp_no = ?;");
			stmt.setInt(1, empno);
			final ResultSet resSet = stmt.executeQuery();
			String firstName = "";
			String lastName = "";
			while (resSet.next()){
                	 	firstName = resSet.getString("first_name");
                	 	lastName = resSet.getString("last_name");
			}

			if (firstName.isEmpty()){
				System.out.printf("Employee with id %d does not exist .\n", empno);
			}else{
				final PreparedStatement del = conn.prepareStatement("delete from employees where emp_no = ?;");
				del.setInt(1, empno);
				del.executeUpdate();
				System.out.printf("Employee %s %s deleted!\n", firstName, lastName );
			}

			} catch (Exception e) {
				// TODO: handle exception
							System.out.printf("THREW EXCEPTION FOR DELETE\n");
			}
	}

	private static void addEmployees(final String firstname,final String lastname,final String deptname,final String birthdate,final String gender,final String salary) {
			try {
			
			// String empString = "max(emp_no)";
			final Statement prest = conn.createStatement();
			final ResultSet preset = prest.executeQuery("Select max(emp_no) from employees");
			int newempno = 0;
			while(preset.next()){
			newempno = preset.getInt("max(emp_no)");
			}
			newempno++;



			// System.out.printf("Employee %s %s employee number generated: %d\n", first_name, last_name, newempno);

			final PreparedStatement predep = conn.prepareStatement("Select dept_no from departments where dept_name = ?");
			predep.setString(1, deptname);
			final ResultSet redep = predep.executeQuery();
			String departno = "";
			while(redep.next()){
			departno = redep.getString("dept_no");
			}

			final Date enddate = Date.valueOf("9999-01-01");
			
			// System.out.printf("Employee %s %s dept_no aquired: %s\n", first_name, last_name, departno);

			
			final PreparedStatement stmt = conn.prepareStatement("INSERT INTO employees VALUES(?, ?, ?, ?, ?, ?);");
			final Date date = Date.valueOf(LocalDate.now());
			stmt.setInt(1, newempno);   // employees.emp_no
			stmt.setDate(2, Date.valueOf(birthdate));	//employees.birth_date
			stmt.setString(3, firstname);	//employees.first_name
			stmt.setString(4, lastname);   //employees.last_name
			stmt.setString(5, gender);   //employees.gender
			stmt.setDate(6, date); 		//employees.hire_date
			// System.out.printf("STMT succussful\n");

			final PreparedStatement stmt2 = conn.prepareStatement("INSERT INTO salaries VALUES(?, ?, ?, ?);");
			stmt2.setInt(1, newempno);    //salaries.emp_no
			stmt2.setString(2, salary);	//salaries.salary
			stmt2.setDate(3, date);		//salaries.from_date
			stmt2.setDate(4, enddate);	//salaries.to_date

			// System.out.printf("stmt2 successful\n");
			final PreparedStatement stmt3 = conn.prepareStatement("INSERT INTO dept_emp VALUES(?, ?, ?, ?);");
			stmt3.setInt(1, newempno);		//dept_emp.emp_no
			stmt3.setString(2, departno);	//dept_emp.departno
			stmt3.setDate(3, date);		//dept_emp.from_date
			stmt3.setDate(4, enddate);	//dept_emp.to_date
			
			stmt.executeUpdate();
			stmt2.executeUpdate();
			stmt3.executeUpdate();
			
			System.out.printf("Employee %s %s added!\n", firstname, lastname);

			} catch (SQLException e) {
			e.printStackTrace();
			}
	}

	private static void showEmployeesByDepepartment(final String string) {
		try {
			final PreparedStatement stmt = conn.prepareStatement("SELECT * FROM employees NATURAL JOIN dept_emp NATURAL JOIN departments where dept_name = ?");
			stmt.setString(1, string);
			final ResultSet resSet = stmt.executeQuery();
			while (resSet.next()){
                	 	final int empNo = resSet.getInt("emp_no"); // Adjust the column names to match your table
                	 	final String firstName = resSet.getString("first_name");
                	 	final String lastName = resSet.getString("last_name");
                	 	System.out.printf("%-10d\t%-20s\t%-20s\n", empNo, firstName, lastName );
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}