package model.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import model.to.CoursesTO;
import model.to.StudentsTO;

public class StudentsDAO {

    private String errormessage;

    public String getErrormessage() {
        return errormessage;
    }

    public boolean insertRecord(StudentsTO record) {
        try {
            String query = "insert into students ";
            query += "(name,fathername,contactno,email,dob) ";
            query += " values(?,?,?,?,?)";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1, record.getName());
            stmt.setString(2, record.getFathername());
            stmt.setString(3, record.getContactno());
            stmt.setString(4, record.getEmail());
            stmt.setDate(5, record.getDob());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public boolean updateRecord(StudentsTO record) {
        try {
            String query = "update students ";
            query += " set name=?,fathername=?,contactno=?,email=?,dob=? ";
            query += " where rollno=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1, record.getName());
            stmt.setString(2, record.getFathername());
            stmt.setString(3, record.getContactno());
            stmt.setString(4, record.getEmail());
            stmt.setDate(5, record.getDob());
            stmt.setInt(6, record.getRollno());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public boolean deleteRecord(int rollno) {
        try {
            String query = "delete from students ";
            query += " where rollno=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setInt(1, rollno);
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public StudentsTO getRecord(int rollno) {
        try {
            String query = "select rollno , name , fathername , contactno , email , dob ";
            query += " from students ";
            query += " where rollno=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setInt(1, rollno);
            StudentsTO result = null;
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                result = new StudentsTO();
                result.setRollno(rs.getInt("rollno"));
                result.setName(rs.getString("name"));
                result.setFathername(rs.getString("fathername"));
                result.setEmail(rs.getString("email"));
                result.setContactno(rs.getString("contactno"));
                result.setDob(rs.getDate("dob"));
            }
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return null;
        }
    }
}
