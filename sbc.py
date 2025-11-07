import hashlib
import time
import json

# 定义一个区块类
class Block:
    def __init__(self, index, timestamp, data, previous_hash):
        self.index = index
        self.timestamp = timestamp
        self.data = data
        self.previous_hash = previous_hash
        self.hash = self.calculate_hash()
    
    def calculate_hash(self):
        block_string = f"{self.index}{self.timestamp}{self.data}{self.previous_hash}"
        return hashlib.sha256(block_string.encode()).hexdigest()

# 定义区块链类
class Blockchain:
    def __init__(self):
        self.chain = [self.create_genesis_block()]
    
    def create_genesis_block(self):
        # 创世区块
        return Block(0, time.time(), "Genesis Block", "0")
    
    def get_latest_block(self):
        return self.chain[-1]
    
    def add_block(self, data):
        previous_block = self.get_latest_block()
        new_block = Block(
            index=previous_block.index + 1,
            timestamp=time.time(),
            data=data,
            previous_hash=previous_block.hash
        )
        self.chain.append(new_block)
    
    def is_chain_valid(self):
        # 验证区块链是否有效
        for i in range(1, len(self.chain)):
            current = self.chain[i]
            previous = self.chain[i-1]
            if current.hash != current.calculate_hash():
                return False
            if current.previous_hash != previous.hash:
                return False
        return True

# 测试区块链
if __name__ == "__main__":
    my_blockchain = Blockchain()
    
    my_blockchain.add_block("First block data")
    my_blockchain.add_block("Second block data")
    
    for block in my_blockchain.chain:
        print(f"Index: {block.index}")
        print(f"Timestamp: {block.timestamp}")
        print(f"Data: {block.data}")
        print(f"Previous Hash: {block.previous_hash}")
        print(f"Hash: {block.hash}")
        print("-"*30)
    
    print("Is blockchain valid?", my_blockchain.is_chain_valid())
