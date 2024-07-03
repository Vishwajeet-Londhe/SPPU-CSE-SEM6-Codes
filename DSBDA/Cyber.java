/* Design a distributed application using MapReduce which processes a log file of a system. List out the
users who have logged for maximum period on the system. Use simple log file from the Internet and
process it using a pseudo distribution mode on Hadoop platform. */
import java.util.*;
import java.io.IOException;
import java.io.IOException;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.util.*;
public class Cyber
{
	//Mapper class
	public static class E_EMapper extends MapReduceBase implements
	Mapper<LongWritable ,/*Input key Type */
	Text, /*Input value Type*/
	Text, /*Output key Type*/
	IntWritable> /*Output value Type*/
	{
		//Map function
		public void map(LongWritable key, Text value,
		OutputCollector<Text, IntWritable> output,
		Reporter reporter) throws IOException
		{
			String line = value.toString();
			int lasttoken = 00;
			StringTokenizer s = new StringTokenizer(line,"\t");
			String name = s.nextToken();
			while(s.hasMoreTokens())
				{
				 lasttoken += (Integer.parseInt(s.nextToken())); //add all the elements
 				}		
		int avgtime = lasttoken/7;  // calculate average
		output.collect(new Text(name), new IntWritable(avgtime));
		}
	}
	//Reducer class
	public static class E_EReduce extends MapReduceBase implements
	Reducer< Text, IntWritable, Text, IntWritable >
	{
		//Reduce function
		public void reduce(
		Text key,
		Iterator <IntWritable> values,
		OutputCollector<Text, IntWritable> output,
		Reporter reporter) throws IOException
		{
			int avg=5;		//threshold value for max time internet usage
			int val=0;
			while (values.hasNext())
			{
				if((val=values.next().get())>avg)
				{
					output.collect(key, new IntWritable(val));
				}
			}
		}
	}
	//Main function
	public static void main(String args[])throws Exception
	{
		JobConf conf = new JobConf(Cyber.class);
		conf.setJobName("Internet Log");
		conf.setOutputKeyClass(Text.class);
		conf.setOutputValueClass(IntWritable.class);
		conf.setMapperClass(E_EMapper.class);
		conf.setCombinerClass(E_EReduce.class);
		conf.setReducerClass(E_EReduce.class);
		conf.setInputFormat(TextInputFormat.class);
		conf.setOutputFormat(TextOutputFormat.class);
		FileInputFormat.setInputPaths(conf, new Path(args[0]));
		FileOutputFormat.setOutputPath(conf, new Path(args[1]));
		JobClient.runJob(conf);
	}
}
