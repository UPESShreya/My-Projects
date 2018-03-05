package model.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import model.to.LoginInfoTO;

public class LoginInfoDAO {
    private String errormessage;

    public String getErrormessage() {
        return errormessage;
    }
    
    public boolean insertRecord(LoginInfoTO record){
        try{
            String query = "insert into logininfo ";
            query += "(username,password,rolename,lastlogin) ";
            query += " values(?,?,?,null)";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1,record.getUsername());
            stmt.setString(2,record.getPassword());
            stmt.setString(3,record.getRolename());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        }catch(Exception ex){
            errormessage = ex.toString();
            return false;
        }
    }
    
    public boolean updateRecord(LoginInfoTO record){
        try{
            String query = "update logininfo ";
            query += " set password=?,rolename=?,lastlogin=? ";
            query += " where username=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1,record.getPassword());
            stmt.setString(2,record.getRolename());
            stmt.setTimestamp(3, record.getLastlogin());
            stmt.setString(4,record.getUsername());
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        }catch(Exception ex){
            errormessage = ex.toString();
            return false;
        }
    }
    
    public boolean deleteRecord(String username){
        try{
            String query = "delete from logininfo ";
            query += " where username=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1,username);
            boolean result = stmt.executeUpdate() > 0;
            stmt.close();
            return result;
        }catch(Exception ex){
            errormessage = ex.toString();
            return false;
        }
    }
    
    public LoginInfoTO getRecord(String username){
        try{
            String query = "select username , password , rolename , lastlogin ";
            query += " from logininfo ";
            query += " where username=?";
            PreparedStatement stmt = DataConnection.getStatement(query);
            stmt.setString(1,username);
            LoginInfoTO result =null;
            ResultSet rs = stmt.executeQuery();
            if(rs.next()){
                result = new LoginInfoTO();
                result.setUsername(rs.getString("username"));
                result.setPassword(rs.getString("password"));
                result.setRolename(rs.getString("rolename"));
                result.setLastlogin(rs.getTimestamp("lastlogin"));
            }
            stmt.close();
            return result;
        }catch(Exception ex){
            errormessage = ex.toString();
            return null;
        }
    }
}
