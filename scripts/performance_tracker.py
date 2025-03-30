import json
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime
import os

def load_benchmarks():
    with open('results.json') as f:
        data = json.load(f)
    return [{
        'name': b['name'],
        'cpu_time': b['cpu_time'],
        'bytes_per_second': b.get('bytes_per_second', 0),
        'items_per_second': b.get('items_per_second', 0),
        'date': datetime.now().strftime('%Y-%m-%d')
    } for b in data['benchmarks']]

def save_report(data):
    os.makedirs('performance_data', exist_ok=True)
    history_file = 'performance_data/history.csv'
    
    # Load existing data
    try:
        history = pd.read_csv(history_file)
        df = pd.concat([history, pd.DataFrame(data)])
    except FileNotFoundError:
        df = pd.DataFrame(data)
    
    # Save updated data
    df.to_csv(history_file, index=False)
    
    # Generate visualization
    plt.style.use('seaborn')
    fig, ax = plt.subplots(figsize=(12, 6))
    
    for metric in ['cpu_time', 'bytes_per_second']:
        if metric in df.columns:
            df.groupby(['name', 'date'])[metric].mean().unstack().T.plot(ax=ax)
    
    ax.set_title('Performance Trends')
    ax.set_ylabel('Time (ns) / Throughput')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.savefig('performance_report.png')

if __name__ == '__main__':
    benchmark_data = load_benchmarks()
    save_report(benchmark_data)