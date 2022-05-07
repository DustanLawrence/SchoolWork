package com.olympic.cis143.m04.student.tacotruck.set;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

import com.olympic.cis143.m04.student.tacotruck.Orders;
import com.olympic.cis143.m04.student.tacotruck.TacoImpl;

public class OrdersSetImpl  implements Orders {
	
	Set<TacoImpl> tacoQueue = new LinkedHashSet<>();
	
    @Override
    public void addOrder(TacoImpl tacoOrder) {
    	this.tacoQueue.add(tacoOrder);
    }

    @Override
    public boolean hasNext() {
        return !this.tacoQueue.isEmpty();
    }

    @Override
    public TacoImpl closeNextOrder() {
    	TacoImpl TacoImpl = tacoQueue.iterator().next();
    	tacoQueue.remove(TacoImpl);    	
        return TacoImpl;
    }

    @Override
    public int howManyOrders() {
        return this.tacoQueue.size();
    }
}
