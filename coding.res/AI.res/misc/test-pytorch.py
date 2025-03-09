#output should be = tensor([1.], device='mps:0')

# import torch
# if torch.backends.mps.is_available():
#     mps_device = torch.device("mps")
#     x = torch.ones(1, device=mps_device)
#     print (x)
# else:
#     print ("MPS device not found.")
    
import torch
import timeit


def test_GPU_vs_CPU(device):
    if device == "cpu":
        x = torch.rand((10000, 10000), dtype=torch.float32)
        y = torch.rand((10000, 10000), dtype=torch.float32)
    else:
        # by creating the tensors on the GPU we avoid OVERHEAD transfering the tensors from the CPU to the GPU, similar above it will save us a lot of time when traing on the GPU
        x = torch.rand((10000, 10000), dtype=torch.float32, device=device)
        y = torch.rand((10000, 10000), dtype=torch.float32, device=device)
        
    # x = x.to(device)
    # y = y.to(device)
    x * y



numberTimesToRun = 10

""" Without using GPU """
device = torch.device('cpu')
execution_CPU_time = timeit.timeit(lambda: test_GPU_vs_CPU(device), number=numberTimesToRun)

print(f"\nCPU Execution time: {execution_CPU_time:.5f} seconds")



"""Using GPU (5x faster)"""
device = torch.device('mps')

execution_CPU_time = timeit.timeit(lambda: test_GPU_vs_CPU(device), number=numberTimesToRun)
print(f"\nGPU Execution time: {execution_CPU_time:.5f} seconds")

