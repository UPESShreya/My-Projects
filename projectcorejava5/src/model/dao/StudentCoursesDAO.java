package model.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import model.to.StudentCoursesTO;
import model.to.StudentsTO;

public class StudentCoursesDAO {

    private String errormessage;

    public String getErrormessage() {
        return errormessage;
    }

    public boolean insertRecord(StudentCoursesTO record) {
        try {
            String query = "insert into studentcourses ";
            query += "(rollno,courseid,fee,startdate,enddate) ";
            query += " values(?,?,?,?,null)";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setInt(1, record.getRollno());
            stmt.setString(2, record.getCourseid());
            stmt.setInt(3, record.getFee());
            stmt.setDate(4, record.getStartdate());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public boolean updateRecord(StudentCoursesTO record) {
        try {
            String query = "update studentcourses ";
            query += " set rollno=?,courseid=?,fee=?,startdate=?,enddate=? ";
            query += " where srno=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setInt(1, record.getRollno());
            stmt.setString(2, record.getCourseid());
            stmt.setInt(3, record.getFee());
            stmt.setDate(4, record.getStartdate());
            stmt.setDate(5, record.getEnddate());
            stmt.setInt(6, record.getSrno());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public boolean deleteRecord(int srno) {
        try {
            String query = "delete from studentcourses ";
            query += " where srno=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setInt(1, srno);
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public StudentCoursesTO getRecord(int srno) {
        try {
            String query = "select srno ,rollno,courseid , fee , startdate , enddate ";
            query += " from studentcourses ";
            query += " where srno=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setInt(1, srno);
            StudentCoursesTO result = null;
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                result = new StudentCoursesTO();
                result.setSrno(rs.getInt("srno"));
                result.setRollno(rs.getInt("rollno"));
                result.setCourseid(rs.getString("courseid"));
                result.setFee(rs.getInt("fee"));
                result.setStartdate(rs.getDate("startdate"));
                result.setStartdate(rs.getDate("enddate"));
            }
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return null;
        }
    }
}
