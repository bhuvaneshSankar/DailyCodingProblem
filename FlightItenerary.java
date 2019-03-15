import java.util.HashMap;
import java.util.Map;
public class FlightItenerary{
    public static void main(String[] args){
        HashMap<String, String> dataSet = new HashMap<String, String>();
        dataSet.put("chennai", "banglore");
        dataSet.put("goa", "chennai");
        dataSet.put("delhi", "goa");
        dataSet.put("bombay", "delhi");
        
        FlightItenerary object = new FlightItenerary();
        object.findItenerary(dataSet);
    }

    void findItenerary(HashMap<String, String> dataSet){
        HashMap<String, String> reversedataSet = new HashMap<String, String>();
        for(Map.Entry<String, String> entry : dataSet.entrySet()){
            reversedataSet.put(entry.getValue(), entry.getKey());
        }
        String start = "";
        for(Map.Entry<String, String> entry : dataSet.entrySet()){
            if(!reversedataSet.containsKey(entry.getKey())){
                start = entry.getKey();
            }
        }
        String to = dataSet.get(start);
        while(to!=null){
            System.out.println(start+"->"+to);
            start = to;
            to = dataSet.get(start);

        }
    }
}   