package model.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DataConnection {

    private static Connection con = null;

    private DataConnection() {
    }

    public static Connection getConnection() {
        try {
            if (con == null) {
                Class.forName("com.mysql.jdbc.Driver");
                String connectionurl = "jdbc:mysql://localhost:3306/corejava5";
                String dbuser = "root";
                String dbpass = "";
                con = DriverManager.getConnection(connectionurl, dbuser, dbpass);
            }
            return con;
        } catch (Exception ex) {
            ex.printStackTrace();
            return null;
        }
    }
    
    public static PreparedStatement getStatement(String query){
        try{
            PreparedStatement stmt = getConnection().prepareStatement(query);
            return stmt;
        }catch(Exception ex){
            ex.printStackTrace();
            return null;
        }
    }

    public static void closeConnection() {
        try {
            if (con != null) {
                con.close();
            }
            con = null;
        }catch(SQLException ex){
            ex.printStackTrace();
        }
    }
}
