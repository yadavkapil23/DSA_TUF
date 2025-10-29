import React, { useState } from 'react';
import { Play, SkipForward, RotateCcw } from 'lucide-react';

const RecursionFlowVisualization = () => {
  const [step, setStep] = useState(0);
  
  const steps = [
    {
      title: "Initial Call",
      active: "Call 1",
      stack: [
        { id: 1, line: "Line 1", status: "executing", ds: "[]", target: 7, ind: 0 }
      ],
      description: "Start: ind=0, target=7, ds=[]"
    },
    {
      title: "Call 1 - Line 1",
      active: "Call 1",
      stack: [
        { id: 1, line: "Line 1", status: "done", ds: "[2]", target: 7, ind: 0 }
      ],
      description: "✅ Push 2 → ds=[2]"
    },
    {
      title: "Call 1 - Line 2",
      active: "Call 1",
      stack: [
        { id: 1, line: "Line 2", status: "calling", ds: "[2]", target: 7, ind: 0 }
      ],
      description: "📞 Calling findCombination(0, 5, ...) → Jump to Call 2"
    },
    {
      title: "Call 2 Starts",
      active: "Call 2",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2]", target: 7, ind: 0 },
        { id: 2, line: "Line 1", status: "executing", ds: "[2]", target: 5, ind: 0 }
      ],
      description: "⏸️ Call 1 PAUSED at Line 3. Call 2 starts: ind=0, target=5"
    },
    {
      title: "Call 2 - Line 1",
      active: "Call 2",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 1", status: "done", ds: "[2, 2]", target: 5, ind: 0 }
      ],
      description: "✅ Push 2 → ds=[2, 2]"
    },
    {
      title: "Call 2 - Line 2",
      active: "Call 2",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 2", status: "calling", ds: "[2, 2]", target: 5, ind: 0 }
      ],
      description: "📞 Calling findCombination(0, 3, ...) → Jump to Call 3"
    },
    {
      title: "Call 3 Starts",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 1", status: "executing", ds: "[2, 2]", target: 3, ind: 0 }
      ],
      description: "⏸️ Call 2 PAUSED at Line 3. Call 3 starts: ind=0, target=3"
    },
    {
      title: "Call 3 - Line 1",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 1", status: "done", ds: "[2, 2, 2]", target: 3, ind: 0 }
      ],
      description: "✅ Push 2 → ds=[2, 2, 2]"
    },
    {
      title: "Call 3 - Line 2",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 2", status: "calling", ds: "[2, 2, 2]", target: 3, ind: 0 }
      ],
      description: "📞 Calling findCombination(0, 1, ...) → Jump to Call 4"
    },
    {
      title: "Call 4 Starts",
      active: "Call 4",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 3, ind: 0 },
        { id: 4, line: "Check", status: "executing", ds: "[2, 2, 2]", target: 1, ind: 0 }
      ],
      description: "⏸️ Call 3 PAUSED. Call 4: ind=0, target=1. Check: 2 <= 1? NO!"
    },
    {
      title: "Call 4 - Skip & Line 4",
      active: "Call 4",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 3, ind: 0 },
        { id: 4, line: "Line 4", status: "executing", ds: "[2, 2, 2]", target: 1, ind: 0 }
      ],
      description: "❌ Skip if block. Execute Line 4: Try next index (ind=1)"
    },
    {
      title: "Call 4 RETURNS",
      active: "Call 4",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 3, ind: 0 },
        { id: 4, line: "Return", status: "returning", ds: "[2, 2, 2]", target: 1, ind: 0 }
      ],
      description: "↩️ Call 4 finishes and RETURNS to Call 3"
    },
    {
      title: "Call 3 RESUMES - Line 3",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 3", status: "executing", ds: "[2, 2, 2]", target: 3, ind: 0 }
      ],
      description: "▶️ Call 3 RESUMES! Execute Line 3: pop_back()"
    },
    {
      title: "Call 3 - After Pop",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 3", status: "done", ds: "[2, 2]", target: 3, ind: 0 }
      ],
      description: "✅ ds.pop_back() → ds=[2, 2]"
    },
    {
      title: "Call 3 - Line 4",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Line 4", status: "executing", ds: "[2, 2]", target: 3, ind: 0 }
      ],
      description: "Execute Line 4: Try next index (ind=1)"
    },
    {
      title: "Call 3 RETURNS",
      active: "Call 3",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 5, ind: 0 },
        { id: 3, line: "Return", status: "returning", ds: "[2, 2]", target: 3, ind: 0 }
      ],
      description: "↩️ Call 3 finishes and RETURNS to Call 2"
    },
    {
      title: "Call 2 RESUMES - Line 3",
      active: "Call 2",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2, 2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "executing", ds: "[2, 2]", target: 5, ind: 0 }
      ],
      description: "▶️ Call 2 RESUMES! Execute Line 3: pop_back()"
    },
    {
      title: "Call 2 - After Pop",
      active: "Call 2",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2]", target: 7, ind: 0 },
        { id: 2, line: "Line 3", status: "done", ds: "[2]", target: 5, ind: 0 }
      ],
      description: "✅ ds.pop_back() → ds=[2]"
    },
    {
      title: "Call 2 RETURNS",
      active: "Call 2",
      stack: [
        { id: 1, line: "Line 3", status: "waiting", ds: "[2]", target: 7, ind: 0 },
        { id: 2, line: "Return", status: "returning", ds: "[2]", target: 5, ind: 0 }
      ],
      description: "↩️ Call 2 finishes and RETURNS to Call 1"
    },
    {
      title: "Call 1 RESUMES - Line 3",
      active: "Call 1",
      stack: [
        { id: 1, line: "Line 3", status: "executing", ds: "[2]", target: 7, ind: 0 }
      ],
      description: "▶️ Call 1 RESUMES! Execute Line 3: pop_back()"
    },
    {
      title: "Call 1 - After Pop",
      active: "Call 1",
      stack: [
        { id: 1, line: "Line 3", status: "done", ds: "[]", target: 7, ind: 0 }
      ],
      description: "✅ ds.pop_back() → ds=[]"
    }
  ];

  const getStatusColor = (status) => {
    switch(status) {
      case 'executing': return 'bg-green-500';
      case 'calling': return 'bg-blue-500';
      case 'waiting': return 'bg-yellow-500';
      case 'done': return 'bg-gray-400';
      case 'returning': return 'bg-purple-500';
      default: return 'bg-gray-300';
    }
  };

  const getStatusEmoji = (status) => {
    switch(status) {
      case 'executing': return '⚡';
      case 'calling': return '📞';
      case 'waiting': return '⏸️';
      case 'done': return '✅';
      case 'returning': return '↩️';
      default: return '';
    }
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-slate-900 to-slate-800 p-8">
      <div className="max-w-6xl mx-auto">
        <h1 className="text-4xl font-bold text-white mb-2 text-center">
          Recursion Call Stack Visualization
        </h1>
        <p className="text-slate-300 text-center mb-8">
          Watch how recursive calls stack up and unwind with backtracking
        </p>

        {/* Controls */}
        <div className="bg-slate-800 rounded-lg p-6 mb-6 border border-slate-700">
          <div className="flex items-center justify-between mb-4">
            <div className="text-white">
              <span className="text-sm text-slate-400">Step {step + 1} of {steps.length}</span>
              <h2 className="text-2xl font-bold">{steps[step].title}</h2>
            </div>
            <div className="flex gap-2">
              <button
                onClick={() => setStep(0)}
                className="bg-slate-700 hover:bg-slate-600 text-white px-4 py-2 rounded-lg flex items-center gap-2"
              >
                <RotateCcw size={16} /> Reset
              </button>
              <button
                onClick={() => setStep(Math.max(0, step - 1))}
                disabled={step === 0}
                className="bg-slate-700 hover:bg-slate-600 text-white px-4 py-2 rounded-lg disabled:opacity-50"
              >
                ← Previous
              </button>
              <button
                onClick={() => setStep(Math.min(steps.length - 1, step + 1))}
                disabled={step === steps.length - 1}
                className="bg-blue-600 hover:bg-blue-700 text-white px-4 py-2 rounded-lg flex items-center gap-2 disabled:opacity-50"
              >
                Next → <SkipForward size={16} />
              </button>
            </div>
          </div>
          
          <div className="bg-slate-900 rounded-lg p-4 border border-slate-600">
            <p className="text-slate-200 text-lg">{steps[step].description}</p>
          </div>
        </div>

        {/* Call Stack */}
        <div className="bg-slate-800 rounded-lg p-6 border border-slate-700">
          <h3 className="text-xl font-bold text-white mb-4">📚 Call Stack (Top = Currently Active)</h3>
          
          <div className="space-y-3">
            {[...steps[step].stack].reverse().map((call, idx) => (
              <div
                key={call.id}
                className={`rounded-lg p-4 border-2 transition-all ${
                  call.status === 'executing' || call.status === 'calling'
                    ? 'border-green-400 bg-slate-700'
                    : call.status === 'returning'
                    ? 'border-purple-400 bg-slate-700'
                    : 'border-slate-600 bg-slate-900'
                }`}
              >
                <div className="flex items-center justify-between">
                  <div className="flex items-center gap-3">
                    <div className={`w-3 h-3 rounded-full ${getStatusColor(call.status)}`}></div>
                    <span className="text-white font-bold">Call {call.id}</span>
                    <span className="text-slate-400">at {call.line}</span>
                    <span className="text-2xl">{getStatusEmoji(call.status)}</span>
                  </div>
                  <div className="flex gap-4 text-sm">
                    <span className="text-slate-300">ind={call.ind}</span>
                    <span className="text-slate-300">target={call.target}</span>
                    <span className="text-blue-400 font-mono">ds={call.ds}</span>
                  </div>
                </div>
              </div>
            ))}
          </div>

          {/* Legend */}
          <div className="mt-6 pt-4 border-t border-slate-700">
            <p className="text-slate-400 text-sm mb-2">Status Legend:</p>
            <div className="flex flex-wrap gap-4 text-sm">
              <div className="flex items-center gap-2">
                <div className="w-3 h-3 rounded-full bg-green-500"></div>
                <span className="text-slate-300">⚡ Executing</span>
              </div>
              <div className="flex items-center gap-2">
                <div className="w-3 h-3 rounded-full bg-blue-500"></div>
                <span className="text-slate-300">📞 Calling Next</span>
              </div>
              <div className="flex items-center gap-2">
                <div className="w-3 h-3 rounded-full bg-yellow-500"></div>
                <span className="text-slate-300">⏸️ Waiting/Paused</span>
              </div>
              <div className="flex items-center gap-2">
                <div className="w-3 h-3 rounded-full bg-purple-500"></div>
                <span className="text-slate-300">↩️ Returning</span>
              </div>
              <div className="flex items-center gap-2">
                <div className="w-3 h-3 rounded-full bg-gray-400"></div>
                <span className="text-slate-300">✅ Done</span>
              </div>
            </div>
          </div>
        </div>

        {/* Code Reference */}
        <div className="mt-6 bg-slate-800 rounded-lg p-6 border border-slate-700">
          <h3 className="text-xl font-bold text-white mb-4">📝 Code Reference</h3>
          <pre className="bg-slate-900 p-4 rounded-lg text-slate-300 text-sm overflow-x-auto">
{`void findCombination(...) {
    if (v[ind] <= target) {
        ds.push_back(v[ind]);              // Line 1
        findCombination(ind, target - v[ind], ...);  // Line 2
        ds.pop_back();                     // Line 3 ⬅️ WAITS HERE!
    }
    findCombination(ind + 1, target, ...); // Line 4
}`}
          </pre>
        </div>
      </div>
    </div>
  );
};

export default RecursionFlowVisualization;