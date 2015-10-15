package com.cloudslee.javatest;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import com.cloudslee.javatest.testGenericClass.TestDerivativeFromAbstract;
import com.cloudslee.javatest.testGenericClass.TestDerivativeFromClass;
import com.cloudslee.javatest.testGenericClass.TestGenericAbstract;
import com.cloudslee.javatest.testGenericClass.TestGenericClass;
import com.cloudslee.rutile.db_fields.SrStockinfo;
import com.cloudslee.rutile.db_fields.StockRecord;
import com.cloudslee.rutile.db_fields.Stockinfo;
import com.cloudslee.util.Datecode;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Unit test for simple App.
 */
public class AppTest
		extends TestCase {
	/**
	 * Create the test case
	 *
	 * @param testName
	 *            name of the test case
	 */
	public AppTest(String testName) {
		super(testName);
	}

	/**
	 * @return the suite of tests being tested
	 */
	public static Test suite() {
		return new TestSuite(AppTest.class);
	}

	/**
	 * Rigourous Test :-)
	 * 
	 * @throws IllegalAccessException
	 * @throws IllegalArgumentException
	 */
	public void testStockRecord()
	{
		SrStockinfo sti = new SrStockinfo();
		
		sti.body.name = "聯發科";
		
		System.out.println(sti);
	}
	
	@SuppressWarnings("unused")
	public void testGenericClass()
	{
		/*
		 * 這方法只能抓SuperClass的GenericType,所以GenericType物件必須被繼承後才能用
		 */
		System.out.println("OK: new a Interface ( a anonymous derivatived object)");
		TestGenericAbstract<Integer> objTGA = new TestGenericAbstract<Integer>(){};
		
		System.out.println("OK: new a anonymous derivateved object");
		TestGenericClass<Integer> objTGCC = new TestGenericClass<Integer>(){};
		
		System.out.println("Failed: new a Object");
		TestGenericClass<Integer> objTGCO = new TestGenericClass<Integer>();
		
		System.out.println("OK: new a Derivatived Object");
		TestDerivativeFromClass objTDFC = new TestDerivativeFromClass();
		
		System.out.println("OK: new a Derivatived Abstract Object ==> suggest this usage");
		TestDerivativeFromAbstract objTDFA = new TestDerivativeFromAbstract();
		
		
	}
	
	public void testClassClass() throws IllegalArgumentException, IllegalAccessException {
		TestClass tc = new TestClass();
		Class<?> clazz = tc.getClass();
		tc.m_var1 = 123;
		tc.m_var2 = 456;

		System.out.println(tc.getClass());
		System.out.println(clazz.getName());

		System.out.println("Methods------");
		for (Method element : clazz.getMethods()) {
			System.out.println(element.getName());
		}

		System.out.println("Fields------");
		for (Field element : clazz.getFields()) {
			System.out.println(element.getName());
			System.out.println(element.getType().toString());
			System.out.println(element.getInt(tc));
		}
	}
	
	public void testClassPOJO() throws IllegalArgumentException, IllegalAccessException {
		SrStockinfo tc = new SrStockinfo();
		// TestClass tc = new TestClass();
		@SuppressWarnings("unchecked")
		Class<SrStockinfo> clazz = (Class<SrStockinfo>) tc.getClass();
		tc.code = "2454";
		tc.getBody().name = "聯發科";
		tc.getBody().list_date = 20150930;

		System.out.println("tc.getClass() = " + tc.getClass());
		System.out.println("clazz.getName() = " + clazz.getName());

		System.out.println("Methods=======");
		for (Method element : clazz.getMethods()) {
			System.out.println(element.getName());
		}

		System.out.println("Fields=======");
		for (Field element : clazz.getFields()) {
			System.out.println("------");
			System.out.println("field name :" + element.getName());
			System.out.println("field Class is Primitive :" + element.getClass().isPrimitive());
			System.out.println("field type :" + element.getType().getName());
			System.out.println("field value :" + element.get(tc));//com.cloudslee.rutile.db_fields.Stockinfo@7006c658??!!
			
			if(element.get(tc) != null){
				System.out.println("field Object Class Name :" + element.get(tc).getClass().getName());
			}
			
			if( element.getType().getName().equals("java.lang.Object") ){
				System.out.println("\tthis is embedded object");
				
				/*
				 * element 是 clazz getFields()來的,clazz是StockRecord<Stockinfo>.getClass()來的.
				 * StockRecord<Stockinfo>的getClass得到的應該是StockRecord<T>
				 * 所以body只知道是java.lang.Object這個class
				 */
				//Class<?> clazz_l2 = element.getClass(); 
				
				Class<?> clazz_l2 = Stockinfo.class;
				
				System.out.println("\tClass name : " + clazz_l2.getName());
				for (Field element_l2 : clazz_l2.getFields()) {
					System.out.println("------");
					System.out.println("\tfield name :" + element_l2.getName());
					System.out.println("\tfield Class is Primitive :" + element_l2.getClass().isPrimitive());
					System.out.println("\tfield type :" + element_l2.getType().getName());
					System.out.println("\tfield value :" + element_l2.get(element.get(tc)/*tc.body()*/)); //傳入實體
					if(element_l2.get(element.get(tc)/*tc.body()*/) != null){
						System.out.println("\tfield Object Class Name :" + element_l2.get(element.get(tc)/*tc.body()*/).getClass().getName());
					}
				}
				
			}
		}
		
		
		/**
		 * 
		 */
		Class<? extends Stockinfo> body_clazz =  tc.getBody().getClass();
		
		System.out.println(body_clazz); //class com.cloudslee.rutile.db_fields.Stockinfo
		
	}

	public void testClassPOJO_TEST() throws IllegalArgumentException, IllegalAccessException {
		SrStockinfo tc = new SrStockinfo();
		// TestClass tc = new TestClass();
		@SuppressWarnings("unchecked")
		Class<SrStockinfo> clazz = (Class<SrStockinfo>) tc.getClass();
		tc.code = "2454";
		tc.getBody().name = "聯發科";
		tc.getBody().list_date = 20150930;

		System.out.println("tc.getClass() = " + tc.getClass());
		System.out.println("clazz.getName() = " + clazz.getName());

		System.out.println("Methods=======");
		for (Method element : clazz.getMethods()) {
			System.out.println(element.getName());
		}

		System.out.println("Fields=======");
		for (Field element : clazz.getFields()) {
			System.out.println("------");
			System.out.println("field name :" + element.getName());
			System.out.println("field type :" + element.getType().getName());
			System.out.println("field value :" + element.get(tc));//com.cloudslee.rutile.db_fields.Stockinfo@7006c658??!!
			
			if(element.get(tc) != null){
				System.out.println("field Object Class Name :" + element.get(tc).getClass().getName());
			}
			
			if( element.getType().getName().equals("java.lang.Object") ){
				System.out.println("\tthis is embedded object");
				
				/*
				 * element 是 clazz getFields()來的,clazz是StockRecord<Stockinfo>.getClass()來的.
				 * StockRecord<Stockinfo>的getClass得到的應該是StockRecord<T>
				 * 所以body只知道是java.lang.Object這個class
				 */
				//Class<?> clazz_l2 = element.getClass(); 
				
				Class<?> clazz_l2 = Stockinfo.class;
				
				System.out.println("\tClass name : " + clazz_l2.getName());
				for (Field element_l2 : clazz_l2.getFields()) {
					System.out.println("------");
					System.out.println("\tfield name :" + element_l2.getName());
					System.out.println("\tfield type :" + element_l2.getType().getName());
					System.out.println("\tfield value :" + element_l2.get(/*element.get(tc)*/tc.getBody())); //傳入實體
					if(element_l2.get(element.get(tc)/*tc.body()*/) != null){
						System.out.println("\tfield Object Class Name :" + element_l2.get(/*element.get(tc)*/tc.getBody()).getClass().getName());
					}
				}
				
			}
		}
		
		
		/**
		 * 
		 */
		Class<? extends Stockinfo> body_clazz =  tc.getBody().getClass();
		
		System.out.println(body_clazz); //class com.cloudslee.rutile.db_fields.Stockinfo
		
	}
}
