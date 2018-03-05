package model.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import model.to.CoursesTO;
import model.to.LoginInfoTO;

public class CoursesDAO {

    private String errormessage;

    public String getErrormessage() {
        return errormessage;
    }

    public boolean insertRecord(CoursesTO record) {
        try {
            String query = "insert into courses ";
            query += "(courseid,coursename,coursefee) ";
            query += " values(?,?,?)";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1, record.getCourseid());
            stmt.setString(2, record.getCoursename());
            stmt.setInt(3, record.getCoursefee());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public boolean updateRecord(CoursesTO record) {
        try {
            String query = "update courses ";
            query += " set coursename=?,coursefee=? ";
            query += " where courseid=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1, record.getCoursename());
            stmt.setInt(2, record.getCoursefee());
            stmt.setString(3, record.getCourseid());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public boolean deleteRecord(String courseid) {
        try {
            String query = "delete from courses ";
            query += " where courseid=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1, courseid);
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return false;
        }
    }

    public CoursesTO getRecord(String courseid) {
        try {
            String query = "select courseid , coursename, coursefee ";
            query += " from courses ";
            query += " where courseid=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1, courseid);
            CoursesTO result = null;
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                result = new CoursesTO();
                result.setCourseid(rs.getString("courseid"));
                result.setCoursename(rs.getString("coursename"));
                result.setCoursefee(rs.getInt("coursefee"));
            }
            stmt.close();
            return result;
        } catch (Exception ex) {
            errormessage = ex.toString();
            return null;
        }
    }
}
